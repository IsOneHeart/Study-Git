import Pref from '@ohos.data.preferences'
import {
  defaultFromNum,
  defaultToNum,
  defaultResultNum,
  defaultNumType,
  defaultCount,
  defaultRandomArr,
  defaultProgress,
  defaultWantSort,
  defaultAver,
  defaultPrecision,
  defaultExclusionArr,
  defaultDelNum
} from '../random_sys/random_component'

const DB_NAME = 'IsOneHeart' //存储名
const KEY_SIZE = 'keySize' //键，保存字体大小
const KEY_COLOR = 'keyColor' //键，保存字体颜色
const KEY_FROM_NUM = 'keyFromNum'
const KEY_TO_NUM = 'keyToNum'
const KEY_RESULT_NUM = 'keyResultNum'
const KEY_NUM_TYPE = 'keyNumType'
const KEY_COUNT = 'KeyCount'
const KEY_RANDOM_ARR = 'keyRandomArr'
const KEY_PROGRESS = 'keyProgress'
const KEY_WANT_SORT = 'keyWantSort'
const KEY_AVER = 'keyAver'
const KEY_PRECISION = 'keyPrecision'
const KEY_EXCLUSION_ARR = 'keyExclusionArr'
const KEY_DEL_NUM = 'keyDelNum'

class PrefUtil {
  defineGetFontPreferences(context) {
    //定义全局对象
    globalThis.getFontPreferences = (() => {
      let pref = Pref.getPreferences(context, DB_NAME)
      return pref
    })
  }

  //保存样式，包括大小和颜色
  saveFontStyle(fontSize: number, fontColor: string) {
    globalThis.getFontPreferences().then((preferences) => {
      preferences.put(KEY_SIZE, fontSize)
      preferences.put(KEY_COLOR, fontColor)
      preferences.flush()
    }).catch((err) => {
      console.error('保存失败,err：' + err)
    })
  }

  //获取字体大小
  async getFontSize() {
    let fontSize: number = 18 //defaultSize
    const preferences = await globalThis.getFontPreferences()
    fontSize = await preferences.get(KEY_SIZE, fontSize)
    return fontSize
  }

  //获取字体颜色
  async getFontColor() {
    let fontColor: string = 'Color.Black' //defaultColor
    const preferences = await globalThis.getFontPreferences()
    //从数据库中获取颜色，如果无，则使用默认值
    fontColor = await preferences.get(KEY_COLOR, fontColor)
    return fontColor
  }
}

export class PrefRandom {
  defineGetRandomPreferences(context) {
    //定义全局对象
    globalThis.getRandomPreferences = (() => {
      let pref = Pref.getPreferences(context, DB_NAME)
      return pref
    })
  }

  saveDB(fromNum: string, toNum: string, resultNum: string, numType: number, count: number, randomArr: Array<string>,
         progress: number, wantSort: boolean, aver: number, precision: number, exclusionArr: Array<string>, delNum: Array<String>) {
    globalThis.getRandomPreferences().then((preferences) => {
      preferences.put(KEY_FROM_NUM, fromNum)
      preferences.put(KEY_TO_NUM, toNum)
      preferences.put(KEY_RESULT_NUM, resultNum)
      preferences.put(KEY_NUM_TYPE, numType)
      preferences.put(KEY_COUNT, count)
      preferences.put(KEY_RANDOM_ARR, randomArr)
      preferences.put(KEY_PROGRESS, progress)
      preferences.put(KEY_WANT_SORT, wantSort)
      preferences.put(KEY_AVER, aver)
      preferences.put(KEY_PRECISION, precision)
      preferences.put(KEY_EXCLUSION_ARR, exclusionArr)
      preferences.put(KEY_DEL_NUM, delNum)
      preferences.flush()
    }).catch((err) => {
      console.error('保存失败,err：' + err)
    })
  }

  async getFromNum() {
    let from_num: string = defaultFromNum
    const preferences = await globalThis.getRandomPreferences()
    from_num = await preferences.get(KEY_FROM_NUM, from_num)
    return from_num
  }

  async getToNum() {
    let to_num: string = defaultToNum
    const preferences = await globalThis.getRandomPreferences()
    to_num = await preferences.get(KEY_TO_NUM, to_num)
    return to_num
  }

  async getResultNum() {
    let result_num: string = defaultResultNum
    const preferences = await globalThis.getRandomPreferences()
    result_num = await preferences.get(KEY_RESULT_NUM, result_num)
    return result_num
  }

  async getNumType() {
    let num_type: number = defaultNumType
    const preferences = await globalThis.getRandomPreferences()
    num_type = await preferences.get(KEY_NUM_TYPE, num_type)
    return num_type
  }

  async getCount() {
    let count: number = defaultCount
    const preferences = await globalThis.getRandomPreferences()
    count = await preferences.get(KEY_COUNT, count)
    return count
  }

  async getRandomArr() {
    let random_arr: Array<string> = defaultRandomArr
    const preferences = await globalThis.getRandomPreferences()
    random_arr = await preferences.get(KEY_RANDOM_ARR, random_arr)
    return random_arr
  }

  async getProgress() {
    let progress: number = defaultProgress
    const preferences = await globalThis.getRandomPreferences()
    progress = await preferences.get(KEY_PROGRESS, progress)
    return progress
  }

  async getWantSort() {
    let want_sort: boolean = defaultWantSort
    const preferences = await globalThis.getRandomPreferences()
    want_sort = await preferences.get(KEY_WANT_SORT, want_sort)
    return want_sort
  }

  async getAver() {
    let aver: number = defaultAver
    const preferences = await globalThis.getRandomPreferences()
    aver = await preferences.get(KEY_AVER, aver)
    return aver
  }

  async getPrecision() {
    let precision: number = defaultPrecision
    const preferences = await globalThis.getRandomPreferences()
    precision = await preferences.get(KEY_PRECISION, precision)
    return precision
  }

  async getExclusionArr() {
    let exclusion_arr: Array<string> = defaultExclusionArr
    const preferences = await globalThis.getRandomPreferences()
    exclusion_arr = await preferences.get(KEY_EXCLUSION_ARR, exclusion_arr)
    return exclusion_arr
  }

  async getDelNum() {
    let del_num: Array<String> = defaultDelNum
    const preferences = await globalThis.getRandomPreferences()
    del_num = await preferences.get(KEY_DEL_NUM, del_num)
    return del_num
  }
}

export default new PrefRandom() //导出对象