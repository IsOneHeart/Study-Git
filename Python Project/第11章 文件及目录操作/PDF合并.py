import PyPDF2

# 打开三个PDF文件
pdf1_file = open('D:/相册/高中时光/学习资料/张奕鑫高三反思本（上）.pdf', 'rb')
pdf2_file = open('D:/相册/高中时光/学习资料/张奕鑫高三反思本（中）.pdf', 'rb')
pdf3_file = open('D:/相册/高中时光/学习资料/张奕鑫高三反思本（下）.pdf', 'rb')

# 创建一个PDF写入对象
pdf_writer = PyPDF2.PdfWriter()

# 读取每个PDF文件的所有页面并添加到写入对象中
for pdf_file in [pdf1_file, pdf2_file, pdf3_file]:
    pdf_reader = PyPDF2.PdfReader(pdf_file)
    for page_num in range(len(pdf_reader.pages)):
        page = pdf_reader.pages[page_num]
        pdf_writer.add_page(page)

# 将合并后的PDF写入一个新文件
output_file = open('D:/相册/高中时光/学习资料/张奕鑫高三反思本.pdf', 'wb')
pdf_writer.write(output_file)

# 关闭所有文件
pdf1_file.close()
pdf2_file.close()
pdf3_file.close()
output_file.close()
