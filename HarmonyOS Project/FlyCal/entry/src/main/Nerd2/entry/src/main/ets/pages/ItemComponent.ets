@Component
export default struct ItemComponent{
  private book_title : string

  @State isCompete : boolean = false

  @Builder
  CreateIcon(icon:Resource){
    Image(icon)
      .width(20)
      .height(20)
      .objectFit(ImageFit.Contain)
      .margin(20)
  }

  build(){
    Row(){

      if (this.isCompete){
        this.CreateIcon($r('app.media.ic_public_todo_filled'))
      }
      else{
        this.CreateIcon($r('app.media.ic_public_todo'))
      }

      Text(this.book_title)
        .fontSize(18)
        .fontWeight(500)
        .decoration({type:this.isCompete?TextDecorationType.LineThrough:TextDecorationType.None})
        .opacity(this.isCompete?0.5:1)
    }
    .borderRadius(24)
    .backgroundColor(Color.White)
    .width('93%')
    .height(65)
    .onClick(()=>{
      this.isCompete=!this.isCompete
    })
  }
}