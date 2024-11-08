import { router } from '@kit.ArkUI'
import { PathData } from '../model/PathData'
import { ZoomController } from '../component/ZoomController'
import { ToolBar } from '../component/ToolBar'

@Entry
@Component
struct Painting {
  @State path: string = ''
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  private img: ImageBitmap = new ImageBitmap('')
  @State imgChanged: boolean = false
  //@State pixelMap: image.PixelMap | null = null
  private offCanvas: OffscreenCanvas = new OffscreenCanvas(this.context.width, this.context.height)
  private offContext: OffscreenCanvasRenderingContext2D =
    new OffscreenCanvasRenderingContext2D(this.context.width, this.context.height, this.settings)
  @State @Watch('onScaleFactorUpdate') scaleFactor: number = 50
  @State pinchValue: number = 1;
  @State pinchX: number = 0;
  @State pinchY: number = 0;
  //@State touchAngle: number = 0
  @State @Watch('onScaleFactorUpdate') offsetX: number = 0;
  @State @Watch('onScaleFactorUpdate') offsetY: number = 0;
  private centerX = 0
  private centerY = 0
  @State moveAble: boolean = true
  @State drawAble: boolean = false
  //@State imgX: number = 0
  //@State imgY: number = 0
  @State hiddenCanvas:OffscreenCanvas=new OffscreenCanvas(this.img.width,this.img.height)

  onScaleFactorUpdate(propName: string): void {
    this.processImage()
  }

  async processImage(touchX: number = 0, touchY: number = 0) {
    this.offCanvas = new OffscreenCanvas(this.offCanvas.width, this.offCanvas.height)
    this.adjustCanvasSize()
    let offContext = this.offCanvas.getContext("2d", this.settings)
    // 清除画布上的所有内容
    offContext.clearRect(0, 0, this.offCanvas.width, this.offCanvas.height);
    this.drawCheckerboardBackground()
    // 图片原始宽度和高度
    const originalWidth = this.img.width;
    const originalHeight = this.img.height;
    // 计算缩放后的宽度和高度
    const scaledWidth = originalWidth * this.scaleFactor;
    const scaledHeight = originalHeight * this.scaleFactor;
    offContext.imageSmoothingEnabled = false; //防止放大后模糊
    // 计算图片居中时的起始位置
    this.centerX = (this.context.width - scaledWidth) / 2 + this.offsetX;
    this.centerY = (this.context.height - scaledHeight) / 2 + this.offsetY;
    // 在画布上绘制缩放后的图片
    offContext.drawImage(
      this.img, // 源图像
      0, 0, // 源图像的裁剪区域起始点 (x, y)
      originalWidth, originalHeight, // 源图像的裁剪区域大小 (width, height)
      this.centerX, this.centerY, // 目标画布上的绘制位置 (x, y)
      scaledWidth, scaledHeight       // 目标画布上的绘制大小 (width, height)
    );
    if (touchX != 0 && touchY != 0) {
      const w = this.getUIContext().vp2px(this.img.width), h = this.getUIContext().vp2px(this.img.height);
      const pixelW = this.scaleFactor * this.img.width / w; //单个像素大小
      const pixelH = this.scaleFactor * this.img.height / h;
      let touchPixelX: number = touchX, touchPixelY: number = touchY;
      for (let i = 0; i < w; i++) {
        if (touchPixelX > this.centerX + i * pixelW && touchPixelX < this.centerX + (i + 1) * pixelW) {
          touchPixelX = this.centerX + i * pixelW;
        }
      }
      for (let i = 0; i < h; i++) {
        if (touchPixelY > this.centerY + i * pixelH && touchPixelY < this.centerY + (i + 1) * pixelH) {
          touchPixelY = this.centerY + i * pixelH;
        }
      }
      offContext.fillStyle = Color.Red
      offContext.fillRect(touchPixelX, touchPixelY, pixelW, pixelH);
      //let image = this.offContext.transferToImageBitmap();
      //this.context.transferFromImageBitmap(image);
    }
    let image = this.offCanvas.transferToImageBitmap()
    this.context.transferFromImageBitmap(image)
    this.img = await this.scaleImageBitmap(await this.cropImageBitmap(image, this.centerX, this.centerY, scaledWidth,
      scaledHeight), 1 / this.scaleFactor)
  }

  adjustCanvasSize() {
    const imgWidth = this.img.width * this.scaleFactor;
    const imgHeight = this.img.height * this.scaleFactor;
    let newWidth = this.context.width;
    let newHeight = this.context.height;
    if(imgWidth>newWidth){
      newWidth=imgWidth
    }
    if(imgHeight>newHeight){
      newHeight=newHeight
    }
    this.offCanvas = new OffscreenCanvas(newWidth, newHeight);
    this.offContext = this.offCanvas.getContext("2d", this.settings) as OffscreenCanvasRenderingContext2D;
  }

  async cropImageBitmap(imageBitmap: ImageBitmap, sx: number, sy: number, sw: number, sh: number) {
    // 创建一个OffscreenCanvas，大小与裁剪区域相同
    const offscreenCanvas = new OffscreenCanvas(sw, sh);
    const offscreenContext = offscreenCanvas.getContext('2d');
    // 使用drawImage方法绘制裁剪后的图像
    offscreenContext.drawImage(imageBitmap, sx, sy, sw, sh, 0, 0, sw, sh);
    // 将OffscreenCanvas转换为新的ImageBitmap
    const croppedImageBitmap = await offscreenCanvas.transferToImageBitmap();
    return croppedImageBitmap;
  }

  async scaleImageBitmap(imageBitmap: ImageBitmap, scale: number) {
    // 获取原始图像的宽度和高度
    const originalWidth = imageBitmap.width;
    const originalHeight = imageBitmap.height;
    // 计算缩放后的宽度和高度
    const scaledWidth = originalWidth * scale;
    const scaledHeight = originalHeight * scale;
    // 创建一个OffscreenCanvas，大小为缩放后的尺寸
    const offscreenCanvas = new OffscreenCanvas(scaledWidth, scaledHeight);
    const offscreenContext = offscreenCanvas.getContext('2d');
    // 使用drawImage方法绘制缩放后的图像
    offscreenContext.drawImage(imageBitmap, 0, 0, originalWidth, originalHeight, 0, 0, scaledWidth, scaledHeight);
    // 将OffscreenCanvas转换为新的ImageBitmap
    const scaledImageBitmap = await offscreenCanvas.transferToImageBitmap();
    return scaledImageBitmap;
  }

  draw(event: TouchEvent) {
    //在画布中
    if (this.drawAble) {
      this.processImage(event.touches[0].x, event.touches[0].y)
    }
  }

  aboutToAppear() {
    const params = this.getUIContext().getRouter().getParams() as PathData;
    this.path = params.path;
    this.img = new ImageBitmap(this.path)
    this.adjustCanvasSize()
    // this.processImage().then(() => {
    //   if (this.pixelMap) {
    //     this.context.setPixelMap(this.pixelMap);
    //   }
    // });
  }

  build() {
    RelativeContainer() {
      //Stack() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')//.backgroundColor('#ffff00')
          .onReady(() => {
            this.processImage()
          })
          .onTouch((event: TouchEvent) => {
            //this.imgX = event.touches[0].x
            //this.imgY = event.touches[0].y
            this.draw(event)
          })
          .gesture(
            GestureGroup(GestureMode.Parallel,
              // 捏合手势
              PinchGesture({ fingers: 2 })
                .onActionStart((event: GestureEvent | undefined) => {
                  console.info('Pinch start');
                })// 当捏合手势触发时，通过回调函数获取缩放比例，从而修改组件的缩放比例
                .onActionUpdate((event: GestureEvent | undefined) => {
                  if (event) {
                    if (this.scaleFactor * event.scale * 0.5 < 100 && this.scaleFactor * event.scale * 0.5 > 1) {
                      this.scaleFactor *= event.scale * 0.5
                    } else if (this.scaleFactor * event.scale * 0.5 >= 100) {
                      this.scaleFactor = 100
                    } else {
                      this.scaleFactor = 1
                    }
                    //this.processImage();
                    this.pinchX = event.pinchCenterX;
                    this.pinchY = event.pinchCenterY;
                  }
                })
                .onActionEnd(() => {
                  this.pinchValue = this.scaleFactor;
                  console.info('Pinch end');
                }),
              // 滑动手势
              PanGesture({ fingers: 1 })
                .onActionUpdate((event: GestureEvent | undefined) => {
                  if (event && this.moveAble) {
                    //this.touchAngle = event.angle
                    if (Math.abs(this.offsetX + event.offsetX * 0.5) < this.context.width / 3) {
                      this.offsetX += event.offsetX * 0.5
                    }
                    if (Math.abs(this.offsetY + event.offsetY * 0.5) < this.context.height / 3) {
                      this.offsetY += event.offsetY * 0.5
                    }
                    //this.offsetX = Math.max(Math.min(this.offsetX + event.offsetX * 0.5, this.context.width / 3), -this.context.width / 3);
                    //this.offsetY = Math.max(Math.min(this.offsetY + event.offsetY * 0.5, this.context.height / 3), -this.context.height / 3);
                    //this.processImage()
                  }
                })
            ))
      }
      // 在组件上绑定缩放比例，通过修改缩放比例来实现组件的缩小或者放大（模糊，不使用）
      //.scale({ x: this.scaleFactor, y: this.scaleFactor, z: 1 }))
      .width('100%')
      .height('100%')

      Row() {
        Image($r('app.media.chevron_left'))
          .margin('5%')
          .onClick(() => {
            router.back()
          })
          .width('5%')
          .alignSelf(ItemAlign.Start)
          .height('5%')
        //Text('' + this.imgX + ' , ' + this.imgY).fontColor(Color.Red)
      }.alignRules({
        top: { anchor: '__container__', align: VerticalAlign.Top },
        left: { anchor: '__container__', align: HorizontalAlign.Start }
      })

      Column() {
        ZoomController({ scaleFactor: this.scaleFactor })
          .height('45%')
        Column() {
        }.height('5%')

        ToolBar({ moveAble: this.moveAble, drawAble: this.drawAble })
          .height('50%%')
      }.alignRules({
        bottom: { anchor: '__container__', align: VerticalAlign.Bottom },
        middle: { anchor: '__container__', align: HorizontalAlign.Center }
      })
      .height('10%')
      //}
    }
    .height('100%')
    .width('100%')
  }

  private drawCheckerboardBackground() { //透明背景绘制方法
    const tileSize = 20 // 方格大小
    const width = this.context.width
    const height = this.context.height
    for (let y = 0; y < height; y += tileSize) {
      for (let x = 0; x < width; x += tileSize) {
        // 通过交替颜色来创建方格效果
        const isLightSquare = (Math.floor(x / tileSize) + Math.floor(y / tileSize)) % 2 === 0
        const color = isLightSquare ? '#FFFFFF' : '#DDDDDD'
        this.context.fillStyle = color
        this.context.fillRect(x, y, tileSize, tileSize)
      }
    }
  }
}