import router from '@ohos.router'

@Entry
@Component
struct Components_Index {
  //——————————————————————————————————
  @State currentIndex: number = 1 // 场景
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

  @State components: Array<Object> = [
    {
      id: 'random_number',
      text: '范围生成随机数',
      background: '',
      icon: '',
      url: 'pages/random_sys/page_random'
    },
    {
      id: 'test',
      text: 'uuid生成',
      background: '',
      icon: '',
      url: 'pages/random_sys/page_uuid'
    },
    {
      id: 'test',
      text: '测试',
      background: '',
      icon: '',
      url: ''
    }
  ]

  @Builder Component_List() {
    Grid(){
      ForEach(this.components, item => {
        GridItem(){
          Column(){
            Image(item.background)
              .height('70%')
              .width('100%')
              .onClick(()=>{
                router.pushUrl({
                  url:item.url
                }) // 压栈方式跳转页面
              })
            Text(item.text)
              .fontSize(18)
              .fontWeight(21)
              .margin('5%')
              .fontColor(Color.Black)
              .maxLines(1)
              .height('20%')
          }
        }
        .margin('2%')
        .borderRadius(24)
        .backgroundColor(Color.White)
        .height('25%')
        .width('45%')
      })
    }
    .width('95%')
    .height('100%')
  }

  //——————————————————————————————————
  @Builder NavigationTitle() {
    Column() {
      Text('场景')
        .fontColor('#182431')
        .fontSize(30)
        .lineHeight(41)
        .fontWeight(700)
        .textAlign(TextAlign.Start)
    }.alignItems(HorizontalAlign.Start)
    //.width('90%')
  }

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

  build() {
    Column() {
      Navigation() {
        this.Component_List()
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
  }
}