# VSCode: Ấn Ctrl + Shirf + V để hiện preview(dễ đọc)

# 1. file danh sách lớp (DanhSachLopHoc.txt)
## (nằm trong folder "__Data__")
	mã lớp(C15)|tên lớp(C50)|niên khóa(int)|

	vd: D21CQCN01-N|2021 - Công nghệ thông tin 1|2021|

---
# 2. file danh sách môn học (DanhSachMonHoc.txt)
## (nằm trong folder "__Data__")

	mã môn học(C15)|tên môn học(C50)|

	vd:
	INT4234|TIN HOC CO SO 1|
	INT5234|TOAN ROI RAC|

---
# 3. file danh sách sinh viên (vd: D21CQCN01.txt) 
## (nằm trong folder "__Data\DanhSachSinhVien__" chứa danh sách sinh viên các lớp)
	mssv(C10)|password(string)|họ(C50)|tên(C15)|giới tính(0 || 1)|

	vd:
	1. N21DCCN042|12345|LE PHUC|KHANG|0|
	2. N21DCCN045|23456|KHANG PHUC|LE|0|
---
# 4. file danh sách điểm thi (vd: N21DCCN042.txt)
## (nằm trong folder "__Data\DanhSachSinhVien\DanhSachDiemThi\'folder các lớp'__" chứa file điểm từng sinh viên)
###	vd: ..\DanhSachDiemThi\D21CQCN01-N\N21DCCN042.txt
	1. mã môn 1(C15)|điểm số 1(float, setDigit(2))|
	2. mã môn 2|điểm số 2|
	....................
	chưa thi: điểm = -1 (< 0)

	vd: 	
	1.	INT4234|5|
	2.	INT5234|-1|
	...........
---
# 5. file danh sách câu hỏi ("DanhSachCauHoi.txt") 
## (nằm trong folder "__Data__")

**Không  sắp xếp theo môn**

	mã môn(C15)|ID(int)|câu hỏi(C200)|lựa chọn 1(C100)|lựa chọn 2(C100)|lựa chọn 3(C100)|lựa chọn 4(C100)|đáp án(short)|

	vd: INT4234|2342|có bao nhiêu viên ngọc rồng?|1|2|3|4|2|

---
# 6. file các câu hỏi đã làm (vd: N21DCCN042.txt) 
## (nằm trong folder "__Data\DanhSachSinhVien\DanhSachCauHoiThi\'folder các lớp'__" chứa file câu hỏi đã thi của sinh viên)
	
	1.	mã môn 1(C15)|ID1(int)|
	2.	mã môn 1|ID2|

	vd:
	INT4234|4253|
	INT5234|62346|
	..............

---
# 7. file tài khoản & mật khẩu (DanhSachTaiKhoan.txt)
## (nằm trong folder "__Data__" chứa các tài khoản của mỗi sinh viên và tài khoản GV)

	MSSV(string)|password(int)|

	vd:
	GV|GV|
	N21DCCN042|12345|
	N21DCCN042|23456|
