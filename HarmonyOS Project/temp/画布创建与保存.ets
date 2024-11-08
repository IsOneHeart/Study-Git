import { BusinessError } from'@ohos.base';
import image from'@ohos.multimedia.image';
import fs from'@ohos.file.fs';
import common from'@ohos.app.ability.common';
import { Logger } from'@ohos/common';

export class CanvasUtils {
  private static readonly TAG: string ='CanvasUtils';
  private static readonly WIDTH: number = 1920;
  private static readonly HEIGHT: number = 1080;

  /**
   *绘制画布
   *
   * @param context上下文
   * @param pixelMap像素图
   * @param path保存路径
   */
  public static async drawCanvas(context: CanvasRenderingContext2D, pixelMap: image.PixelMap, path: string): Promise<void> {
    Logger.info(CanvasUtils.TAG,'drawCanvas');
    context.drawImage(pixelMap, 0, 0, CanvasUtils.WIDTH, CanvasUtils.HEIGHT);
    const image: ImageBitmap = await context.transferToImageBitmap();
    const imagePackerApi: image.ImagePacker = image.createImagePacker();
    let packOpts: image.PackingOption = { format:'image/jpeg', quality: 100 };
    let packedImage: ArrayBuffer = await imagePackerApi.packing(image, packOpts);
    let file: fs.File = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    fs.writeSync(file.fd, packedImage);
    fs.closeSync(file);
  }

  /**
   *创建画布
   *
   * @param context上下文
   * @param width画布宽度
   * @param height画布高度
   */
  public static createCanvas(context: CanvasRenderingContext2D, width: number, height: number): void {
    Logger.info(CanvasUtils.TAG,'createCanvas');
    context.fillRect(0, 0, width, height);
  }
}
