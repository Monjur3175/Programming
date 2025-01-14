import PyPDF2

pdfiles = ["1.pdf","2.pdf"]

marger = PyPDF2.PdfMerger()

for filename in pdfiles:
    pdfFile = open(filename,'rb')
    pdfReader = PyPDF2.PdfReader(pdfFile)
    marger.append(pdfReader)

pdfFile.close()
marger.write('Project Report.pdf')