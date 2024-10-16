ALTER TABLE Course
	ALTER COLUMN schoolYear TINYINT NOT NULL
ALTER TABLE Course
	ALTER COLUMN semester TINYINT NOT NULL
ALTER TABLE Course
	ALTER COLUMN courseNo CHAR(6) NOT NULL
ALTER TABLE Course
	ALTER COLUMN credit VARCHAR(50) NOT NULL
ALTER TABLE Course
	ALTER COLUMN creditHourse TINYINT NOT NULL
ALTER TABLE Course
	ALTER COLUMN courseType1 CHAR(16) NOT NULL
ALTER TABLE Course
	ALTER COLUMN courseType2 CHAR(16) NULL
ALTER TABLE Course
	ALTER COLUMN cegmentType CHAR(16) NULL
ALTER TABLE Course
	ALTER COLUMN examineWay CHAR(16) NOT NULL

ALTER TABLE Major
	ALTER COLUMN majorNo CHAR(4) NOT NULL
ALTER TABLE Major
	ALTER COLUMN GBMajorNo CHAR(6) NOT NULL
ALTER TABLE Major
	ALTER COLUMN majorName VARCHAR(60) NOT NULL
ALTER TABLE Major
	ALTER COLUMN enMajorName VARCHAR(100) NULL
ALTER TABLE Major
	ALTER COLUMN lengthSchool TINYINT NOT NULL
ALTER TABLE Major
	ALTER COLUMN eduLevel CHAR(6) NOT NULL
ALTER TABLE Major
	ALTER COLUMN ddegree CHAR(12) NOT NULL
ALTER TABLE Major
	ALTER COLUMN departmentNo CHAR(12) NOT NULL
ALTER TABLE Major
	ALTER COLUMN department VARCHAR(40) NOT NULL

ALTER TABLE SelectCourse
	ALTER COLUMN sno CHAR(12) NOT NULL
ALTER TABLE SelectCourse
	ALTER COLUMN schoolYear TINYINT NOT NULL
ALTER TABLE SelectCourse
	ALTER COLUMN semester TINYINT NOT NULL
ALTER TABLE SelectCourse
	ALTER COLUMN courseNo CHAR(6) NOT NULL
ALTER TABLE SelectCourse
	ALTER COLUMN score NUMERIC(6,2) NULL

ALTER TABLE Student
	ALTER COLUMN sno CHAR(12) NOT NULL
ALTER TABLE Student
	ALTER COLUMN sname CHAR(16) NOT NULL
ALTER TABLE Student
	ALTER COLUMN sex CHAR(2) NOT NULL
ALTER TABLE Student
	ALTER COLUMN birthday DATE NOT NULL
ALTER TABLE Student
	ALTER COLUMN nationality CHAR(16) NULL
--ALTER TABLE Student
--	ALTER COLUMN native CHAR(8) NULL
ALTER TABLE Student
	ALTER COLUMN political CHAR(12) NULL
ALTER TABLE Student
	ALTER COLUMN district CHAR(12) NOT NULL
ALTER TABLE Student
	ALTER COLUMN studentSource VARCHAR(24) NULL
ALTER TABLE Student
	ALTER COLUMN enterYear DATE NOT NULL
ALTER TABLE Student
	ALTER COLUMN schoolYear TINYINT NOT NULL
ALTER TABLE Student
	ALTER COLUMN class CHAR(24) NOT NULL
ALTER TABLE Student
	ALTER COLUMN majorNo CHAR(4) NOT NULL

ALTER TABLE Course
	ADD CONSTRAINT CoursePK
	PRIMARY KEY(schoolYear, semester, courseNo)

ALTER TABLE Student
	ADD CONSTRAINT StudentPK
	PRIMARY KEY(sno)

ALTER TABLE Student
	ADD CONSTRAINT StudentFK2
	FOREIGN KEY(majorNo)
	REFERENCES Major(majorNo)