import { random_component } from './random_component'
import router from '@ohos.router'

@Entry
@Component
struct Page {
  scroller: Scroller = new Scroller()
  @Builder ScrollContent() {
    Column() {
      //this.NavigationTitle()

      Search({ placeholder: '搜索...' })
        .width('90%')
        .height(40)
        .backgroundColor('#FFFFFF')
        .margin({ top: 8 })

      random_component()
    }

    Text(' \n')
  }

  build() {
    Column() {
      Row(){
        Image($r('app.media.chevron_left'))
          .margin('5%')
          .onClick(() => {
            router.back()
          })
          .width('5%')

        Text('范围随机数生成')
          .textAlign(TextAlign.Start)
          .fontSize(20)
          .width('90%')
      }

      Scroll(this.scroller) {
        this.ScrollContent()
      }
      .height('95%')
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
      .scrollBar(BarState.On) // 滚动条常驻显示
      .scrollBarColor(Color.Gray) // 滚动条颜色
      .scrollBarWidth(6) // 滚动条宽度
      .edgeEffect(EdgeEffect.None)
      .onScroll((xOffset: number, yOffset: number) => {
        console.info(xOffset + ' ' + yOffset)
      })
      .onScrollEdge((side: Edge) => {
        console.info('To the edge')
      })
    }
    .height('100%')
    .backgroundColor('#F1F3F5')
  }
}