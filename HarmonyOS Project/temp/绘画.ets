@Component
struct Draw{
  // ...之前的代码

  @State drawing: boolean = false
  @State lastX: number = 0
  @State lastY: number = 0

  // ...之前的代码

  build() {
    // ...之前的代码

    Canvas(this.context)
      .width('100%')
      .height('100%')
      .onReady(() => {
        // ...之前的代码
      })
      .onTouch((event: TouchEvent) => {
        const touch = event.touches[0];
        const currentX = touch.pageX;
        const currentY = touch.pageY;

        switch (event.type) {
          case 'touchstart':
            this.drawing = true;
            this.lastX = currentX;
            this.lastY = currentY;
            break;
          case 'touchmove':
            if (this.drawing) {
              this.context.beginPath();
              this.context.moveTo(this.lastX, this.lastY);
              this.context.lineTo(currentX, currentY);
              this.context.stroke();
              this.lastX = currentX;
              this.lastY = currentY;
            }
            break;
          case 'touchend':
            this.drawing = false;
            break;
          default:
            break;
        }
      });

    // ...之前的代码
  }

  // ...之前的代码

}