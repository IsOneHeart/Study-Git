function sleeping(ms: number): Promise<void> {
  return new Promise(resolve => setTimeout(resolve, ms));
}

export async function sleep(ms: number) {
  await sleeping(ms); // 等待ms毫秒（sc/1000秒）
}