class Pet:
    def __init__(self, name, animal_type, age):
        self.__name = name
        self.__animal_type = animal_type
        self.__age = age

    def set_name(self):
        self.__name = name

    def set_animal_type(self):
        self.__animal_type=animal_type

    def set_age(self):
        self.__age=age

    def get_name(self):
        return self.__name

    def get_animal_type(self):
        return self.__animal_type

    def get_age(self):
        return self.__age


name=str(input("请输入宠物名字："))
animal_type=str(input("请输入宠物类型："))
age=int(input("请输入宠物年龄："))
pet_i=Pet(name,animal_type,age)
print("名字："+pet_i.get_name())
print("类型："+pet_i.get_animal_type())
print("年龄:"+str(pet_i.get_age()))