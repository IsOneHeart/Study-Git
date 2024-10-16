ALTER TABLE SelectCourse
	ADD CONSTRAINT SelectCourseFK_sno
	FOREIGN KEY(sno) 
	REFERENCES Student(sno) 


