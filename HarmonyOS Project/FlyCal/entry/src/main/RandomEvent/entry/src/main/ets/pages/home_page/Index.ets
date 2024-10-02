import { random_component } from '../random_sys/random_component'
import router from '@ohos.router'
import { uuid_component } from '../random_sys/uuid_component'

@Entry
@Component
struct Index {
  @State message: string = '范围随机数生成'
  @State result_int: string = 'EMPTY'
  @State isTouching: boolean = false
  //——————————————————————————————————
  @State currentIndex: number = 0 // 主页
  @State Build: Array<Object> = [
    {
      text: '主页',
      icon0: ($r("app.media.house_fill_colored")),
      icon1: ($r("app.media.house_fill")),
      num: 0,
      url: 'pages/home_page/Index' // 页面需在main_pages.json中注册
    },
    {
      text: '场景',
      icon0: ($r("app.media.case_fill_colored")),
      icon1: ($r("app.media.case_fill")),
      num: 1,
      url: 'pages/components_page/Components_Index'
    },
    {
      text: '我的',
      icon0: ($r('app.media.person_crop_circle_fill_1_colored')),
      icon1: ($r('app.media.person_crop_circle_fill')),
      num: 2,
      url: 'pages/my_page/My_Index'
    }
  ]
  //——————————————————————————————————
  scroller: Scroller = new Scroller()
  @State page_num: number = 0
  @State more: boolean = false
  @State more_build: Array<Object> = [
    {
      text: '保存当前页面',
      icon: ($r('app.media.save'))
    }
  ]

  @Builder NavigationTitle() {
    Column() {
      Row() {
        Text('工具箱')
          .fontColor('#182431')
          .fontSize(30)
          .lineHeight(41)
          .fontWeight(700)
          .textAlign(TextAlign.Start)
          .width('67%')
        Image($r('app.media.save'))
          .width(30)
          .height(30)
          .margin({ right: '5%' })
        Image($r('app.media.more'))
          .width(30)
          .height(30)
          .onClick(() => {
            this.more = true
          })
      }.width('100%')

      Row() {
        Select([{ value: '范围随机数生成', icon: "/common/public_icon.svg" },
          { value: 'uuid生成', icon: "/common/public_icon.svg" }])
          .selected(2)
          .value('范围随机数生成')
          .font({ size: 14, weight: 500 })
          .fontColor('#182431')
          .opacity(0.4)
          .selectedOptionFont({ size: 16, weight: 400 })
          .optionFont({ size: 16, weight: 400 })
          .onSelect((index: number) => {
            console.info('Page Select:' + index)
            this.page_num = index
          })
          .backgroundColor('#F1F3F5')
      }
    }.alignItems(HorizontalAlign.Start)
    //.width('90%')
  }

  //——————————————————————————————————
  @Builder NavigationToolbar() {
    Row() {
      ForEach(this.Build, item => {
        Column() {
          Image(this.currentIndex == item.num ? item.icon0 : item.icon1)
            .width(24)
            .height(24)
          Text(item.text)
            .fontColor(this.currentIndex == item.num ? '#007DFF' : '#182431')
            .fontSize(10)
            .lineHeight(14)
            .fontWeight(500)
            .margin({ top: 3 })
        }
        //.width(104)
        //.height(56)
        .margin({ left: '30%' })
        .onClick(() => {
          this.currentIndex = item.num
          router.replaceUrl({ // 页面跳转
            url: item.url
          })
        })
      })
    } //.margin({ left: 24 })
    .alignItems(VerticalAlign.Center)
  }
  //——————————————————————————————————

  @Builder ScrollContent() {
    Column() {
      //this.NavigationTitle()

      Search({ placeholder: '搜索...' })
        .width('90%')
        .height(40)
        .backgroundColor('#FFFFFF')
        .margin({ top: 8 })


      if (this.page_num == 0) {
        random_component()
      }
      else if (this.page_num == 1) {
        uuid_component()
      }
    }

    Text(' \n')
  }

  @Builder More_UI() {
    Column() {
      Stack() {
        Column() {
        }.height('100%').width('100%')
        .opacity(0.5)
        .backgroundColor(Color.Black)
        .onClick(()=>{
          this.more=false
        })
        Column() {

        }.height('5%').width('100%')
        .backgroundColor(Color.White)

        Column() {
          /*
                          Column(){
            Image($r('app.media.xmark'))
              .height(30).width(30)
              .onClick(()=>{
                this.more=false
              })
              .margin('5%')
          }.alignItems(HorizontalAlign.End)
           */
          Column() {
            Grid() {
              //ForEach(this.more_build, item => {
                GridItem() {
                  Column() {
                    Column() {
                      Image(($r('app.media.save')))
                        .height(70)
                        .width(70)
                        .margin({ top: 20 })
                        .onClick(() => {
                        })
                    }
                    .height(100)
                    .width(100)
                    .alignItems(HorizontalAlign.Center)
                    .alignSelf(ItemAlign.Center)
                    .align(Alignment.Center)
                    .backgroundColor(Color.White)
                    .borderRadius(24)

                    Text('保存当前页面')
                      .fontSize(18)
                      .fontWeight(21)
                      .margin(5)
                      .fontColor(Color.Gray)
                  }
                  .margin({top:25})
                }.alignSelf(ItemAlign.Start)
              //})
            }
          }.alignItems(HorizontalAlign.Start)
        }.height('40%').width('100%')
        .borderRadius(24)
        .backgroundColor('#F1F3F5')
      }.height('100%').width('100%')
      .align(Alignment.Bottom)
    }.height('100%').width('100%')
  }

  build() {
    Column() {
      Stack() {
        Column() {
          Navigation() {

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
          .width('100%')
          .height('100%')
          .mode(NavigationMode.Stack)
          .backgroundColor('#F1F3F5')
          .title(this.NavigationTitle)
          .titleMode(NavigationTitleMode.Full)
          .toolBar(this.NavigationToolbar)
          .hideTitleBar(false)
          .hideToolBar(false)
          .onTitleModeChange((titleModel: NavigationTitleMode) => {
            console.info('titleMode' + titleModel)
          })
        }

        if (this.more) {
          this.More_UI()
        }
      }
    }
    .width('100%').height('100%')
  }
}
