export class Pixel {
  color: string;
  opacity: number;

  constructor(color: string = '#F1F3F5', opacity: number = 0) {
    this.color = color;
    this.opacity = opacity;
  }
}

export class PixelPanel {
  row: number;
  column: number;
  backgroundColor: string;
  gridColor: string;
  showGrid: boolean;
  name: string;
  pixels: Pixel[][];

  constructor(
    row: number = 1,
    column: number = 1,
    backgroundColor: string = '#ec1c24',
    gridColor: string = '#F1F3F5',
    showGrid: boolean = false,
    name: string = ''
  ) {
    this.row = row;
    this.column = column;
    this.backgroundColor = backgroundColor;
    this.gridColor = gridColor;
    this.showGrid = showGrid;
    this.name = name;
    if (!Number.isInteger(row) || !Number.isInteger(column)) {
      throw new Error('Row and column must be integers.');
    }
    if (row <= 0 || column <= 0) {
      throw new Error('Row and column must be positive integers.');
    }
    if (row > Number.MAX_SAFE_INTEGER || column > Number.MAX_SAFE_INTEGER) {
      throw new Error('Row and column values are too large.');
    }
    this.pixels = new Array(row).fill(null).map(() => new Array(column).fill(null).map(() => new Pixel()));
  }
}

export function imgToPixelPanel(img: ImageBitmap): PixelPanel {
  const w = fp2px(img.width);
  const h = fp2px(img.height);
  let pixelPanel = new PixelPanel(h, w);

  let offscreenCanvas = new OffscreenCanvas(w, h);
  let offContext = offscreenCanvas.getContext('2d') as OffscreenCanvasRenderingContext2D;
  offContext.drawImage(img, 0, 0);
  let imageData = offContext.getImageData(0, 0, w, h);
  pixelPanel.row = h;
  pixelPanel.column = w;
  pixelPanel.pixels=new Array(h).fill(null).map(() => new Array(w).fill(null).map(() => new Pixel()));
  for (let row = 0; row < h; row++) {
    for (let col = 0; col < w; col++) {
      let i = (row * w + col) * 4;
      // 将RGB值转换为十六进制颜色字符串，确保格式正确
      let r = imageData.data[i].toString(16).padStart(2, '0');
      let g = imageData.data[i + 1].toString(16).padStart(2, '0');
      let b = imageData.data[i + 2].toString(16).padStart(2, '0');
      let colorHex = '#' + r + g + b; // 确保这是6位十六进制数
      // 创建Pixel对象并设置颜色和透明度
      pixelPanel.pixels[row][col] = new Pixel(colorHex, imageData.data[i + 3] / 255);
    }
  }
  return pixelPanel;
}


class PixelsDataSource implements IDataSource {
  private pixelPanel: PixelPanel;
  private listeners: DataChangeListener[] = [];

  constructor(pixelPanel: PixelPanel) {
    this.pixelPanel = pixelPanel;
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    this.listeners.push(listener);
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const index = this.listeners.indexOf(listener);
    if (index !== -1) {
      this.listeners.splice(index, 1);
    }
  }

  totalCount(): number {
    return this.pixelPanel.pixels.length;
  }

  getData(index: number): Pixel[] {
    if (index < 0 || index >= this.pixelPanel.pixels.length) {
      throw new Error("Index out of bounds");
    }
    return this.pixelPanel.pixels[index];
  }
}

class PixelDataSource implements IDataSource {
  private pixels: Pixel[];
  private listeners: DataChangeListener[] = [];

  constructor(pixels: Pixel[]) {
    this.pixels = pixels;
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    this.listeners.push(listener);
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const index = this.listeners.indexOf(listener);
    if (index !== -1) {
      this.listeners.splice(index, 1);
    }
  }

  totalCount(): number {
    return this.pixels.length;
  }

  getData(index: number): Pixel {
    if (index < 0 || index >= this.pixels.length) {
      throw new Error("Index out of bounds");
    }
    return this.pixels[index];
  }
}

@Component
export struct NeoPixel {
  @Link scaleFactor: number
  @Link drawingColor: string
  @Link pixelPanel: PixelPanel
  @Prop drawAble: boolean
  private dataSource = new PixelsDataSource(this.pixelPanel)

  aboutToAppear() {
    this.dataSource = new PixelsDataSource(this.pixelPanel)
  }

  build() {
    Column() {
      LazyForEach(this.dataSource, (items: Pixel[]) => {
        Row(){
          LazyForEach(new PixelDataSource(items), (item: Pixel) => {
            Rect()
              .width(2)
              .height(2)
              .fill(item.color == null ? this.pixelPanel.backgroundColor : item.color)
              .fillOpacity(item.opacity == null ? 0 : item.opacity)
              //.stroke(this.pixelPanel.showGrid ? Color.White : 'Neo')
              .onTouch((event: TouchEvent) => {
                if (this.drawAble) {
                  item.color = this.drawingColor
                }
              })
          })
        }
      })
    }
  }
}
