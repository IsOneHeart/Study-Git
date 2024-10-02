import wcurses as curses
import time
import keyboard

# 游戏区域的宽度和高度
WIDTH = 30
HEIGHT = 5

# 恐龙的初始位置
dino_position = 0

# 障碍物的初始位置和速度
obstacle_position = WIDTH
obstacle_speed = 0.1

# 游戏是否结束的标志
game_over = False

# 初始化curses
stdscr = curses.initscr()
curses.curs_set(0)  # 隐藏光标
stdscr.nodelay(1)   # 设置为非阻塞模式


# 渲染游戏界面
def render(stdscr):
    stdscr.clear()

    # 绘制恐龙
    stdscr.addstr(0, dino_position, 'o')

    # 绘制障碍物
    stdscr.addstr(HEIGHT, 0, '-' * int(obstacle_position) + '|')

    stdscr.refresh()


# 更新游戏状态
def update():
    global dino_position, obstacle_position, game_over

    # 根据玩家输入更新恐龙位置
    if keyboard.is_pressed('space'):
        if dino_position == 0:
            dino_position = 1
    else:
        if dino_position == 1:
            dino_position = 0

    # 更新障碍物位置
    obstacle_position -= obstacle_speed

    # 如果障碍物移出屏幕，则重新放置到屏幕最右边
    if obstacle_position < 0:
        obstacle_position = WIDTH

    # 检查是否发生碰撞，游戏是否结束
    if obstacle_position == 1 and dino_position == 1:
        game_over = True


# 主循环
while not game_over:
    # 渲染游戏界面
    render(stdscr)

    # 更新游戏状态
    update()

    # 等待一段时间，以便游戏不会过快
    time.sleep(0.1)

# 游戏结束时显示游戏结束信息
stdscr.addstr(HEIGHT+1, 0, "Game Over!")
stdscr.refresh()
curses.napms(2000)  # 等待2秒
curses.endwin()  # 结束curses
