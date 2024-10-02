class PersonalInformation:
    def __init__(self, name, address, age, phone_number):
        self.name = name
        self.address = address
        self.age = age
        self.phone_number = phone_number

    def get_name(self):
        return self.name

    def set_name(self, name):
        self.name = name

    def get_address(self):
        return self.address

    def set_address(self, address):
        self.address = address

    def get_age(self):
        return self.age

    def set_age(self, age):
        self.age = age

    def get_phone_number(self):
        return self.phone_number

    def set_phone_number(self, phone_number):
        self.phone_number = phone_number


# 创建三个实例
my_info = PersonalInformation("Myself", "My Address", 30, "1234567890")
friend_info = PersonalInformation("Friend", "Friend's Address", 25, "9876543210")
family_info = PersonalInformation("Family", "Family's Address", 40, "5555555555")

# 输出信息
print("我的信息:")
print("姓名:", my_info.get_name())
print("地址:", my_info.get_address())
print("年龄:", my_info.get_age())
print("电话号码:", my_info.get_phone_number())

print("\n朋友的信息:")
print("姓名:", friend_info.get_name())
print("地址:", friend_info.get_address())
print("年龄:", friend_info.get_age())
print("电话号码:", friend_info.get_phone_number())

print("\n家人的信息:")
print("姓名:", family_info.get_name())
print("地址:", family_info.get_address())
print("年龄:", family_info.get_age())
print("电话号码:", family_info.get_phone_number())
