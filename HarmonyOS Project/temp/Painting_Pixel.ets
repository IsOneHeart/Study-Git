import { router } from '@kit.ArkUI'
import { PathData } from '../model/PathData'
import { ZoomController } from '../component/ZoomController'
import { ToolBar } from '../component/ToolBar'
import { PixelPanel, imgToPixelPanel, NeoPixel } from '../model/Pixel'

@Entry
@Component
struct Painting {
  @State path: string = ''
  //private settings: RenderingContextSettings = new RenderingContextSettings(true)
  //private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  private img: ImageBitmap = new ImageBitmap('')
  @State imgChanged: boolean = false
  //@State pixelMap: image.PixelMap | null = null
  //private offCanvas: OffscreenCanvas = new OffscreenCanvas(this.context.width, this.context.height)
  //private offContext: OffscreenCanvasRenderingContext2D =
  //new OffscreenCanvasRenderingContext2D(this.context.width, this.context.height, this.settings)
  //@State @Watch('onScaleFactorUpdate') scaleFactor: number = 50
  @State scaleFactor: number = 5
  @State pinchValue: number = 1;
  @State pinchX: number = 0;
  @State pinchY: number = 0;
  //@State touchAngle: number = 0
  // @State @Watch('onScaleFactorUpdate') offsetX: number = 0;
  // @State @Watch('onScaleFactorUpdate') offsetY: number = 0;
  //private centerX = 0
  //private centerY = 0
  @State moveAble: boolean = true
  @State drawAble: boolean = false
  @State imgX: number = 0
  @State imgY: number = 0
  @State pixelPanel: PixelPanel = new PixelPanel(1, 1, '#F1F3F5', '#F1F3F5', false, '')
  @State drawingColor: string = '#F1F3F5'

  // onScaleFactorUpdate(propName: string): void {
  //   this.processImage()
  // }

  /*  async processImage() {
      this.offCanvas = new OffscreenCanvas(this.context.width, this.context.height)
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
      let image = this.offCanvas.transferToImageBitmap()
      this.context.transferFromImageBitmap(image)
    }

    draw(event: TouchEvent) {
      //在画布中
      if (this.drawAble) {
        // 转换触摸坐标为相对于图片的坐标
        const touchX = event.touches[0].x - this.centerX;
        const touchY = event.touches[0].y - this.centerY;
        // 根据缩放比例调整触摸坐标
        this.imgX = this.getUIContext().vp2px(touchX / this.scaleFactor);
        this.imgY = this.getUIContext().vp2px(touchY / this.scaleFactor);
        // 获取图片的像素数据
        const imageData =
          this.offContext.getImageData(this.getUIContext().vp2px(this.centerX), this.getUIContext().vp2px(this.centerY),
            this.getUIContext().vp2px(this.img.width * this.scaleFactor), this.getUIContext().vp2px(this.img.height *
            this.scaleFactor));
        // 计算触摸点在ImageData中的索引
        const index = Math.floor(this.imgY) * (imageData.width * 4) + Math.floor(this.imgX) * 4;
        // 修改像素颜色（例如，设置为红色）
        imageData.data[index] = 255; // 红色分量
        imageData.data[index + 1] = 0; // 绿色分量
        imageData.data[index + 2] = 0; // 蓝色分量
        imageData.data[index + 3] = 255; // alpha分量
        // 将修改后的像素数据放回画布
        this.context.putImageData(imageData, this.centerX + this.offsetX, this.centerY + this.offsetY);
        let image = this.offContext.transferToImageBitmap()
        //this.context.transferFromImageBitmap(image)
        this.img = image
      }
    }*/

  aboutToAppear() {
    const params = this.getUIContext().getRouter().getParams() as PathData;
    this.path = params.path;
    this.img = new ImageBitmap(this.path)
    this.pixelPanel = imgToPixelPanel(this.img)
    // this.processImage().then(() => {
    //   if (this.pixelMap) {
    //     this.context.setPixelMap(this.pixelMap);
    //   }
    // });
  }

  build() {
    RelativeContainer() {
      //Stack() {
      /*      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
              Canvas(this.context)
                .width('100%')
                .height('100%')//.backgroundColor('#ffff00')
                .onReady(() => {
                  this.processImage()
                })
                .onTouch((event: TouchEvent) => {
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
                          //this.processImage()
                        }
                      })
                  ))
            }
            // 在组件上绑定缩放比例，通过修改缩放比例来实现组件的缩小或者放大（模糊，不使用）
            //.scale({ x: this.scaleFactor, y: this.scaleFactor, z: 1 }))
            .width('100%')
            .height('100%')*/

      NeoPixel({
        pixelPanel: this.pixelPanel,
        scaleFactor: this.scaleFactor,
        drawingColor: this.drawingColor,
        drawAble: this.drawAble
      }).width('90%')
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })

      Row() {
        Image($r('app.media.chevron_left'))
          .margin('5%')
          .onClick(() => {
            router.back()
          })
          .width('5%')
          .alignSelf(ItemAlign.Start)
          .height('5%')
        Text('' + this.pixelPanel.pixels[0][0].color == null ? 'null' : this.pixelPanel.pixels[0][0].color)
          .fontColor(Color.Red)
      }.alignRules({
        top: { anchor: '__container__', align: VerticalAlign.Top },
        left: { anchor: '__container__', align: HorizontalAlign.Start }
      })

      Column() {
        // ZoomController({ scaleFactor: this.scaleFactor })
        //   .height('45%')
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

  /*  private drawCheckerboardBackground() { //透明背景绘制方法
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
    }*/
}