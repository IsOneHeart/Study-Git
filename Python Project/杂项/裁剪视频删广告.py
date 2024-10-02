from moviepy.editor import VideoFileClip, concatenate_videoclips

# 加载视频文件
video = VideoFileClip("your_video.mp4")

# 定义要裁剪的时间段（注意Python中索引是从0开始的，但moviepy使用秒为单位）
start_time = 9 * 60 + 56.50  # 开始时间
end_time = 10 * 60 + 13.13  # 结束时间
start_time2 = 35 * 60 + 15.63
end_time2 = 35 * 60 + 29.58

# 裁剪视频
clip1 = video.subclip(0, start_time)
clip2 = video.subclip(end_time, start_time2)
clip3 = video.subclip(end_time2)

# 合并
final_clip = concatenate_videoclips([clip1, clip2, clip3])

# 导出裁剪后的视频
final_clip.write_videofile("cropped_video.mp4")

# 释放资源
video.close()
final_clip.close()
