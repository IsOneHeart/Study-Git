class Car:
    def __init__(self, year, model, make):
        speed = 0
        self.year = year
        self.model = model
        self.make = make
        self.speed = speed

    def accelerate(self):
        self.speed += 5

    def brake(self):
        self.speed -= 5

    def get_speed(self):
        return self.speed


MyCar = Car(2004, "新能源", "大众")
for i in range(10):
    if i in range(5):
        MyCar.accelerate()
        print("speed:", MyCar.get_speed(), sep="")
    else:
        MyCar.brake()
        print("speed:", MyCar.get_speed(), sep="")
