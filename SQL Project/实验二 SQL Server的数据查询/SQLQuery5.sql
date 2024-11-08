--查询修选了“高等数学”课程的学生学号和姓名
SELECT ST.studentNo,ST.studentName
FROM Student ST
WHERE ST.studentNo IN(
	SELECT SC.studentNo
	FROM SCORE SC,Course CO
	WHERE CO.courseNo=SC.courseNo
	AND Co.courseName='高等数学'
)