@Preview
@Component
export struct ExclusionUI {
  @Link exclusions: Array<string>
  @State adding: boolean = false
  @State newNum: number = undefined
  @State delNums: Array<String> = []
  scrollerE: Scroller = new Scroller()
  controller: TextInputController = new TextInputController()

  build() {
    Column() {
      Row() {
        Text('排除项')
          .textAlign(TextAlign.Start)
          .margin(5)
        Image($r('app.media.trash'))
          .margin(5)
          .height(20)
          .onClick(()=>{
            this.exclusions.filter(item=>!this.delNums.includes(item))
          })
        Image($r('app.media.plus_square'))
          .margin(5)
          .height(20)
          .onClick(() => {
            this.adding = true
          })
        CheckboxGroup({ group: 'checkboxGroup' })
          .selectedColor('#007DFF')
          .onChange((itemName: CheckboxGroupResult) => {
            console.info("checkbox group content" + JSON.stringify(itemName))
          })
        Text('全选').fontSize(14).lineHeight(20).fontColor('#182431').fontWeight(500)
      }

      Row() {
        Image($r('app.media.plus_square'))
          .margin(5)
          .height(20)
          .onClick(() => {
            this.adding = true
          })
        TextInput({ text: this.newNum.toString(), placeholder: '初始数', controller: this.controller })
          .placeholderColor(Color.Grey)
          .placeholderFont({ size: 14, weight: 400 })
          .caretColor(Color.Blue)
          .width('30%')
          .margin(10)
          .fontSize(14)
          .fontColor(Color.Black)
          .onChange((value: string) => {
            this.newNum = Number(value)
          })
      }

      Scroll(this.scrollerE) {
        List() {
          if (this.exclusions == []) {
            ListItem() {
              Text('' + 'EMPTY')
                .width('100%')
                .height(100)
                .fontSize(16)
                .textAlign(TextAlign.Center)
                .borderRadius(10)
                .backgroundColor(0xFFFFFF)
            }

          }
          else {
            ForEach(this.exclusions, (item) => {
              ListItem() {
                Row() {
                  Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
                    .onChange(() =>{
                      this.delNums.push(item)
                    })
                  Text('' + item)
                    .width('100%')
                    .height(100)
                    .fontSize(16)
                    .textAlign(TextAlign.Center)
                    .borderRadius(10)
                    .backgroundColor(0xFFFFFF)
                }
              }
            }, item => item)
          }
        }
        .listDirection(Axis.Vertical) // 排列方向
        .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // 每行之间的分界线
        .edgeEffect(EdgeEffect.Spring) // 滑动到边缘无效果
        .onScrollIndex((firstIndex: number, lastIndex: number) => {
          console.info('first' + firstIndex)
          console.info('last' + lastIndex)
        })
      }
    }
  }
}