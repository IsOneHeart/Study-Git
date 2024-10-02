import {BookDataModel} from './structure'
import ItemComponent from './ItemComponent'

@Entry
@Component
struct BookListIndex {
  private BookList:Array<string>=[]

  aboutToAppear(){
    this.BookList=new BookDataModel().get()
  }

  build() {
    Column({space:5}){
      Text('读书清单')
        .fontSize(25)
        .lineHeight(33)
        .fontWeight(FontWeight.Bold)
        .width('90%')
        .margin({
          top:30,
          bottom:15
        })

      ForEach(this.BookList,(item:string)=>{
        ItemComponent({book_title:item})
      })
    }
    .height('100%')
    .width('100%')
    .backgroundColor('#F1F3F5')
  }
}