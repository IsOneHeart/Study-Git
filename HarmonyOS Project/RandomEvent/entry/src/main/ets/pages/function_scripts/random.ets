export function getRandom(): number {
  return Math.random()
}

export function getRandomInt(min: number, max: number): number {
  min = Math.ceil(min)
  max = Math.floor(max)
  return Math.floor(Math.random() * (max - min + 1)) + min
}

export function getRandomFloat(min: number, max: number, precision: number): number {
  let p: number = Math.pow(10, precision)
  return Math.round((Math.random() * (max - min) + min) * p) / p
}

function boxMullerTransformInt(min: number, max: number, mean = 0, stddev = 1) {
  let u1 = Math.random();
  let u2 = Math.random();

  let sqrt = Math.sqrt(-2.0 * Math.log(u1));
  let theta = 2.0 * Math.PI * u2;
  let z0 = sqrt * Math.cos(theta);
  let z1 = sqrt * Math.sin(theta);

  // 返回两个正态分布的随机数，均值为 mean，标准差为 stddev
  return [mean + stddev * z0, mean + stddev * z1];
}

export function getRandomNormalInt(min: number, max: number, mean: number, stddev: number): number {
  // 使用 boxMullerTransform 生成两个正态分布的随机数
  let [num1, num2] = boxMullerTransformInt(min, max, mean, stddev);
  // 返回其中一个数
  return num1;
}

function boxMullerTransformFloat() {
  let u1 = Math.random();
  let u2 = Math.random();

  let sqrt = Math.sqrt(-2.0 * Math.log(u1));
  let theta = 2.0 * Math.PI * u2;
  let z0 = sqrt * Math.cos(theta);
  return z0; // 只返回一个数，因为我们可以多次调用这个函数来获取另一个数
}

export function getRandomNormalFloat(mean: number, stddev: number, precision: number): number {
  let rawNormal = boxMullerTransformFloat(); // 生成标准正态分布的随机数
  let scaledNormal = mean + stddev * rawNormal; // 调整均值和标准差

  // 根据精度进行四舍五入
  let factor = Math.pow(10, precision);
  return Math.round(scaledNormal * factor) / factor;
}

export function getRandomNum16String(len: number): string {
  let result: string = ''
  for (let i: number = 0;i < len; i++) {
    let random_num: string = getRandomInt(0, 15).toString()
    switch (random_num) {
      case '10':
        random_num = 'a'
        break;
      case '11':
        random_num = 'b'
        break;
      case '12':
        random_num = 'c'
        break;
      case '13':
        random_num = 'd'
        break;
      case '14':
        random_num = 'e'
        break;
      case '15':
        random_num = 'f'
        break;
      default:
        break;
    }
    result += random_num
  }
  return result
}

export function getRandomUuidNString(len: number): string {
  let result: string = ''
  for (let i: number = 0;i < len; i++) {
    let random_num: string = getRandomInt(8, 11).toString()
    switch (random_num) {
      case '10':
        random_num = 'a'
        break;
      case '11':
        random_num = 'b'
        break;
      default:
        break;
    }
    result += random_num
  }
  return result
}

export function uuid_maker4(small: boolean): string {
  let uuid: string = getRandomNum16String(8) + '-' + getRandomNum16String(4) + '-4' + getRandomNum16String(3)
  + '-' + getRandomUuidNString(1) + getRandomNum16String(3) + '-' + getRandomNum16String(12)
  if (!small) {
    uuid = uuid.toUpperCase()
  }
  return uuid
}

