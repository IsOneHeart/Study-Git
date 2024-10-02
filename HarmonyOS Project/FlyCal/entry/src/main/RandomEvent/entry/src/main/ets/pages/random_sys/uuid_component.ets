import { uuid_maker4} from '../function_scripts/random'

@Preview
@Component
export struct uuid_component {
  @State spawn_num:number=2
  controller: TextInputController = new TextInputController()
  @State isTouching: boolean = false
  @State small:number=1
  @State uuid_result:Array<string>=[]

  @Builder result_UI() {
    Column() {
      Text('生成结果')
        //.backgroundColor('#c6e8f7')
        //.fontColor(Color.White)
        .backgroundColor('#F1F3F5')
        .height(30)
        .width('50%')
        .textAlign(TextAlign.Center)
        .borderRadius(24)
        .fontSize(20)
        .margin(10)
      //.fontStyle(FontStyle.Italic)
      //.decoration({type:TextDecorationType.Underline,color:Color.Blue})
      ForEach(this.uuid_result,item=>{
        Text(item)
          .fontSize(20)
          .textAlign(TextAlign.Center)
          .margin({top:'5%'})
          .width('85%')
      })
    }
    .margin('5%')
    .height(this.uuid_result.length<6?'76%':(74*this.spawn_num))
    .width('90%')
    .backgroundColor(Color.White)
    .borderRadius(24)
  }

  build() {
      Column() {
        Row() {
          Text('个数')
            .margin({left:'5%'})
          TextInput({ text: this.spawn_num.toString(), placeholder: '生成个数', controller: this.controller })
            .placeholderColor(Color.Grey)
            .placeholderFont({ size: 14, weight: 400 })
            .caretColor(Color.Blue)
            .width('30%')
            .margin(10)
            .fontSize(14)
            .fontColor(Color.Black)
            .onChange((value: string) => {
              this.spawn_num = Number(value)
            })

          Select([{ value: '大写', icon: "/common/public_icon.svg" },
            { value: '小写', icon: "/common/public_icon.svg" }])
            .selected(2)
            .value('小写')
            .font({ size: 16, weight: 500 })
            .fontColor('#182431')
            .selectedOptionFont({ size: 16, weight: 400 })
            .optionFont({ size: 16, weight: 400 })
            .onSelect((index: number) => {
              console.info('Select small:' + index)
              this.small = index
            })

          Button('开始')
            .onClick(() => {
              this.uuid_result=[] //清空记录
              for(let count=0;count<this.spawn_num;count++){
                this.uuid_result.push(uuid_maker4(this.small==0?false:true)) //调用函数
              }
            })
            .onTouch((
              event: TouchEvent) => {
              if (event.type == TouchType.Down)
                this.isTouching = true
              if (event.type == TouchType.Up)
                this.isTouching = false
            })
            .onHover(
              (isHover: boolean) => {
                  isHover ? this.isTouching = true : this.isTouching = false
              })
            .width('25%')
            .height('5%')
            .backgroundColor(this.isTouching ? '#4683fb' : Color.Blue)
        }
        .margin({top:'5%'})
        .width('90%')
        .borderRadius(24)
        .backgroundColor('#ffffff')
        this.result_UI()
      }
  }
}