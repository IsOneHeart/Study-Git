export class BookDataModel{
  private books:Array<string>=[
    "《三国演义》",
    "《水浒传》",
    "《红楼梦》",
    "《西游记》",
    "《HarmonyOS从入门到精通》"
  ]

  get():Array<string>{
    return this.books
  }
}