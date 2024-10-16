
ALTER TABLE SelectCourse
	ADD CONSTRAINT SelectCourseFK_semester_courseNo
	FOREIGN KEY(schoolYear, semester, courseNo) 
	REFERENCES Course(schoolYear, semester, courseNo) 