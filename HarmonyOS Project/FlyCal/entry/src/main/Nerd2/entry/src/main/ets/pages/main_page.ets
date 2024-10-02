@Entry
@Component
struct Main_page {

  @State isCh : boolean = true

  @Builder
  CreateIcon(icon:Resource){
    Image(icon)
      .width(18)
      .height(18)
      .objectFit(ImageFit.Contain)
      .margin(20)
  }

  @Builder
  CreateCh(title:string){
    Column(){
      Text(title)
        .fontSize(20)
        .lineHeight(20)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.Red)
        .decoration({ type: this.isCh ? TextDecorationType.Underline : TextDecorationType.None })
      //.textAlign(TextAlign.Start)
    }
    .backgroundColor(Color.White)
  }

  @Builder
  CreateName(title:string){
    Row(){
      Text(title)
        .fontSize(20)
        .fontWeight(500)
    }
    //.borderRadius(24)
    //.backgroundColor('#F1F3F5')
    .height('20%')
    .width('50%')
  }

  build() {
    Column({space:10}){
      Row(){}
      .width('100%')
      .height(20)

      Row(){
        Image($r('app.media.ic_user_portrait'))
          .width(25)
          .height(25)
          .objectFit(ImageFit.Contain)
          .margin(20)
        Row(){
          this.CreateIcon($r('app.media.ic_public_search'))
          Text('搜索')
            .fontSize(15)
            .lineHeight(20)
            .width('60%')
            .textAlign(TextAlign.Start)
            .fontColor(Color.Gray)
        }
        .borderRadius(24)
        .backgroundColor(Color.White)
        .width('60%')
        .height(30)

        this.CreateIcon($r('app.media.ic_public_refresh'))
      }
      .backgroundColor('#FFD23C')
      .height('5%')
      .width('100%')

      Row(){
        this.CreateCh('近期榜单')
      }
      .width('95%')
      .height('5%')

      Row(){
          Image($r('app.media.example_book'))
            .width('40%')
            .height('100%')
            .objectFit(ImageFit.Contain)
            .margin(20)
        Column(){
          this.CreateName('红楼梦')
          this.CreateName('活着')
          this.CreateName('1984')
          this.CreateName('哈利·波特')
        }
      }
      .borderRadius(24)
      .backgroundColor(Color.White)
      .width('100%')
      .height('35%')
    }
    .height('100%')
    .width('100%')
    .backgroundColor('#F1F3F5')
    //.backgroundColor('#FFD23C')
  }
}