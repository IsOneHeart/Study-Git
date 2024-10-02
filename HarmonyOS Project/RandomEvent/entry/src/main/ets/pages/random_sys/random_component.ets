import { getRandomInt, getRandomFloat } from '../function_scripts/random'
import  PrefRandom  from '../constants/PrefUtil'

const INT: number = 0
const FLOAT: number = 1

enum randomTypes {
  Uniform, //均匀分布
  Normal //正态分布
}

//首选项存储
export const defaultFromNum: string = '1'

export const defaultToNum: string = '10'

export const defaultResultNum: string = '平均结果\nEMPTY'

export const defaultNumType: number = INT

export const defaultCount: number = 1

export const defaultRandomArr: Array<string> = []

export const defaultProgress: number = 0

export const defaultWantSort: boolean = false

export const defaultAver: number = undefined

export const defaultPrecision: number = 2

export const defaultExclusionArr: Array<string> = []

export const defaultDelNum: Array<String> = []

@Preview
@Component
export struct random_component {
  @State result_num: string = defaultResultNum //结果
  @State isTouching: boolean = false //判断是否触碰“开始”按钮
  @State isOpened: boolean = false
  @State numType: number = defaultNumType
  @State defaultValue: number = defaultCount
  @State random_arr: Array<string> = defaultRandomArr
  @State progress: number = defaultProgress
  @State fromNum: string = defaultFromNum
  @State toNum: string = defaultToNum
  @State wantSort: boolean = defaultWantSort
  @State aver: number = defaultAver
  @State precision: number = defaultPrecision
  @State exclusions_arr: Array<string> = defaultExclusionArr
  @State adding: boolean = false
  @State newNum: string = getRandomInt(Number(this.fromNum), Number(this.toNum)).toString()
  InputController: TextInputController = new TextInputController()
  @State delNums: Array<String> = defaultDelNum
  //@State exclusions_arr: Array<string> = ['1', '5.7', '9']
  controller: TextInputController = new TextInputController()
  scrollerE: Scroller = new Scroller()
  @State distribution: number = randomTypes.Uniform

  private saveRandom():void{
    //let pr:PrefRandom=new PrefRandom()
    PrefRandom.saveDB(this.fromNum,this.toNum,this.result_num,this.numType,this.defaultValue,this.random_arr,this.progress,
    this.wantSort,this.aver,this.precision,this.exclusions_arr,this.delNums)
}

  @Builder result_UI() {
    Column() {
      Text('生成结果')
        //.backgroundColor('#c6e8f7')
        //.fontColor(Color.White)
        .backgroundColor('#F1F3F5')
        .height('15%')
        .width('50%')
        .textAlign(TextAlign.Center)
        .borderRadius(24)
        .fontSize(20)
        .margin(10)
      //.fontStyle(FontStyle.Italic)
      //.decoration({type:TextDecorationType.Underline,color:Color.Blue})

      Text(this.random_arr.toString())
        .fontSize(20)
        .textAlign(TextAlign.Center)
        .height('60%')
        .width('85%')
      //.margin(10)
      //.maxLines(4)
    }
    .height('30%')
    .width('90%')
    .backgroundColor(Color.White)
    .borderRadius(24)
  }

  @Builder PrecisionUI() {
    Column({ space: 5 }) {
      Text('精度')
        .textAlign(TextAlign.Start)
        .height(20)
      Counter() {
        Text(this.precision.toString())
      }
      //.borderRadius(24)
      .onInc(() => {
        if (this.precision <= 3)
          this.precision++
      })
      .onDec(() => {
        if (this.precision >= 1)
          this.precision--
      })
      .alignSelf(ItemAlign.Center)
    }
    .width('50%')
    //.backgroundColor(Color.White)
    .borderRadius(16)
    .height('10%')
  }

  @Builder ExclusionUI() {
    Column() {
      Row() {
        Text('排除项')
          .textAlign(TextAlign.Start)
          .margin({ right: '5%' })
        Image($r('app.media.text_and_arrow_down'))
          .margin({ left: '5%' })
          .height(20)
          .onClick(() => {
            this.exclusions_arr = this.exclusions_arr.sort()
            //this.saveRandom()
          })
        Image($r('app.media.trash'))
          .margin({ left: '5%' })
          .height(20)
          .onClick(() => {
            this.exclusions_arr = this.exclusions_arr.filter(item =>!this.delNums.includes(item))
            //this.saveRandom()
          })
        CheckboxGroup({ group: 'checkboxGroup' })
          .selectedColor('#007DFF')
          .margin({ left: '5%' })
          .onChange((itemName: CheckboxGroupResult) => {
            console.info("checkbox group content" + JSON.stringify(itemName))
          })
        Text('全选')
          .fontSize(14)
          .lineHeight(20)
          .fontColor('#182431')
          .fontWeight(500)
          .margin({ left: '3%' })
      }.width('100%')
      .margin({ left: '7%', top: '5%', bottom: '5%' })

      Row() {
        TextInput({ text: this.newNum, placeholder: '新增', controller: this.InputController })
          .placeholderColor(Color.Grey)
          .placeholderFont({ size: 14, weight: 400 })
          .caretColor(Color.Blue)
          .width('70%')
          .margin({ left: '5%' })
          .fontSize(14)
          .fontColor(Color.Black)
          .onChange((value: string) => {
            this.newNum = value
            //this.saveRandom()
          })

        Image($r('app.media.plus_square'))
          .margin('5%')
          .height(20)
          .onClick(() => {
            this.adding = true
            if (!this.exclusions_arr.includes(this.newNum)) {
              this.exclusions_arr.push(this.newNum)
              console.log(this.newNum + '-> exclusions_arr')
            }
            //this.newNum = undefined
            //this.saveRandom()
          })
      }.width('100%')

      Scroll(this.scrollerE) {
        List() {
          if (this.exclusions_arr.length == 0) {
            ListItem() {
              Text('' + 'EMPTY')
                .width('100%')
                .height('6%')
                .fontSize(16)
                .textAlign(TextAlign.Center)
              //.borderRadius(10)
              //.backgroundColor(0xFFFFFF)
            }
          }
          else {
            ForEach(this.exclusions_arr, (item) => {
              ListItem() {
                Row() {
                  Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
                    .onChange(() => {
                      this.delNums.push(item)
                      //this.saveRandom()
                    })
                    .margin({ left: '5%' })
                  Text('' + item)
                    .width('100%')
                    .height(35)
                    .fontSize(16)
                    .textAlign(TextAlign.Center)
                    .backgroundColor(0xFFFFFF)
                    .margin({ right: '5%' })
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
      //.width('50%')
      //.margin({ left: '5%' })
    }
    .borderRadius(24)
    .backgroundColor(0xFFFFFF)
    .alignItems(HorizontalAlign.Start)
    .width('60%')
    .margin('5%')
    .margin({ left: '6%', top: '5%' })
  }

  @Builder DistributionUI() {
    Column() {
      Select([{ value: '均匀分布', icon: "/common/public_icon.svg" }])
        .selected(2)
        .value('均匀分布')
        .font({ size: 16, weight: 500 })
        .fontColor('#182431')
        .selectedOptionFont({ size: 16, weight: 400 })
        .optionFont({ size: 16, weight: 400 })
        .onSelect((index: number) => {
          console.info('DistributionSelect:' + index)
          this.distribution = index
        })
    }.width('30%')
    .margin({ top: '5%' })
  }

  onPageShow() {
    //显示时加载已保存的值
    //let pr:PrefRandom=new PrefRandom() //实例化
    PrefRandom.getFromNum().then((value)=>{
      this.fromNum=value
    })
    PrefRandom.getToNum().then((value)=>{
      this.toNum=value
    })
    PrefRandom.getResultNum().then((value)=>{
      this.result_num=value
    })
    PrefRandom.getNumType().then((value)=>{
      this.numType=value
    })
    PrefRandom.getCount().then((value)=>{
      this.defaultValue=value
    })
    PrefRandom.getRandomArr().then((value)=>{
      this.random_arr=value
    })
    PrefRandom.getProgress().then((value)=>{
      this.progress=value
    })
    PrefRandom.getWantSort().then((value)=>{
      this.wantSort=value
    })
    PrefRandom.getAver().then((value)=>{
      this.aver=value
    })
    PrefRandom.getPrecision().then((value)=>{
      this.precision=value
    })
    PrefRandom.getExclusionArr().then((value)=>{
      this.exclusions_arr=value
    })
    PrefRandom.getDelNum().then((value)=>{
      this.delNums=value
    })
  }

  build() {
    Column() {
      Row() {
        ProgressUI({
          showStr: this.result_num,
          progressRead: this.progress,
          minNum: Number(this.fromNum),
          maxNum: Number(this.toNum),
          averNum: this.aver,
          precision: this.precision
        })

        Column() {
          TextInput({ text: this.fromNum, placeholder: '初始数', controller: this.controller })
            .placeholderColor(Color.Grey)
            .placeholderFont({ size: 14, weight: 400 })
            .caretColor(Color.Blue)
            .width('30%')
            .margin(10)
            .fontSize(14)
            .fontColor(Color.Black)
            .onChange((value: string) => {
              this.fromNum = value
              //this.saveRandom()
            })

          Image(($r('app.media.arrowshape_down_to_line_fill')))
            .height('7%')

          TextInput({ text: this.toNum, placeholder: '终止数', controller: this.controller })
            .placeholderColor(Color.Grey)
            .placeholderFont({ size: 14, weight: 400 })
            .caretColor(Color.Blue)
            .width('30%')
              //.margin(15)
            .fontSize(14)
            .fontColor(Color.Black)
            .onChange((value: string) => {
              this.toNum = value
              //this.saveRandom()
            })
        }
      }

      Row() {
        Select([{ value: '整数', icon: "/common/public_icon.svg" },
          { value: '小数', icon: "/common/public_icon.svg" }])
          .selected(2)
          .value('整数')
          .font({ size: 16, weight: 500 })
          .fontColor('#182431')
          .selectedOptionFont({ size: 16, weight: 400 })
          .optionFont({ size: 16, weight: 400 })
          .onSelect((index: number) => {
            console.info('Select:' + index)
            this.numType = index
          })

        /*
        Image(this.isOpened ? ($r('app.media.ic_public_arrow_up_0')) : ($r('app.media.ic_public_arrow_down_0')))
          .height('4%')
          .objectFit(ImageFit.Contain)
          .onClick(() => this.isOpened = !this.isOpened)
        */

        Text('  生成后排序').margin({ right: '3%' })
        Checkbox()
          .onChange(() => {
            this.wantSort = !this.wantSort
            //this.saveRandom()
          }).margin({ right: '5%' })

        Button('开始')
          .onClick(() => {
            this.progress = 0
            let randomNum: number
            let sum: number = 0
            this.random_arr.length = this.defaultValue
            switch (this.numType) {
              case INT: { //整型
                for (let i: number = 0;i < this.defaultValue; i++) {
                  do {
                    randomNum = getRandomInt(Number(this.fromNum), Number(this.toNum))
                    let count = 0
                    count++
                    if (count >= Number(this.toNum) - Number(this.fromNum)) {
                      randomNum = undefined
                      break
                    }
                  } while (this.exclusions_arr.includes(randomNum.toString()))
                  this.random_arr[i] = ' ' + `${randomNum}` + ' '
                  this.progress++
                  sum += randomNum
                }
                break
              }
              case FLOAT: { //浮点型
                for (let i: number = 0;i < this.defaultValue; i++) {
                  do {
                    randomNum = getRandomFloat(Number(this.fromNum), Number(this.toNum), this.precision)
                    let count = 0
                    count++
                    if (count >= Number(this.toNum) - Number(this.fromNum)) {
                      randomNum = undefined
                      break
                    }
                  } while (this.exclusions_arr.includes(randomNum.toString()))
                  this.random_arr[i] = ' ' + `${randomNum}` + ' '
                  this.progress++
                  sum += randomNum
                }
                break;
              }
            }
            if (this.wantSort)
              this.random_arr.sort((a, b) => Number(a) - Number(b))
            this.aver = sum / this.defaultValue
            this.result_num = `${randomNum}` // 更新result_int状态
            ////this.saveRandom()
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
      .width('80%')
      .borderRadius(24)
      .backgroundColor('#ffffff')

      Row() {
        ControllerUI({ count: $defaultValue })
          .margin('10%')

        this.PrecisionUI()
      }
      .width('100%')

      this.result_UI()

      Row() {
        Text('更多设置')
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Start)
          .margin({ left: '6%', top: '5%' })
      }
      .width('100%')

      Flex() {
        this.ExclusionUI()
        this.DistributionUI()
      }.width('100%')
    }
  }
}

@Component
struct ProgressUI {
  @Prop showStr: string
  @Prop progressRead: number
  @Prop minNum: number
  @Prop maxNum: number
  @Prop averNum: number
  @Prop precision: number

  build() {
    Row() {
      Row({ space: 20 }) {
        Stack({ alignContent: Alignment.Center }) {
          Progress({ value: 10, total: 100, type: ProgressType.Ring })
            .width('50%')
            .color(Color.Blue)
            .value(this.averNum == undefined ? 0 : 100 * (this.averNum - this.minNum + 1) / (this.maxNum - this.minNum + 1))
            .style({ strokeWidth: 20, scaleCount: 30, scaleWidth: 20 })
            .height('35%')
            .zIndex(1)

          Text('平均\n' + `${Math.round(this.averNum * Math.pow(10, this.precision)) / Math.pow(10, this.precision)}`)
            .fontSize(30)
            .width('45%')
            .fontColor(Color.Blue)
            .zIndex(2)
            .textAlign(TextAlign.Center)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
  }
}

@Component
struct ControllerUI {
  @Link count: number

  build() {
    Column({ space: 5 }) {
      Text('生成个数')
        .textAlign(TextAlign.Start)
        .height(20)
      Counter() {
        Text(this.count.toString())
      }
      //.borderRadius(24)
      .onInc(() => {
        if (this.count <= 9)
          this.count++
      })
      .onDec(() => {
        if (this.count >= 2)
          this.count--
      })
      .alignSelf(ItemAlign.Center)
    }
    //.width('50%')
    //.backgroundColor(Color.White)
    .borderRadius(16)
    .height('10%')
  }
}