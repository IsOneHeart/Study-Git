import { BusinessError } from'@ohos.base';
import picker from'@ohos.file.picker';

export class CodeGenie {
  public static async getFilePath(): Promise<string> {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    let uri: string ='';
    try {
      uri = await documentPicker.select(DocumentSelectOptions);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`Invoke documentPicker.select failed, code is ${err.code}, message is ${err.message}`);
    }
    return uri;
  }
}
