--查询“刘晨”班上同学的学号和姓名。
SELECT ST.studentNo,ST.studentName
FROM Student ST,Class CL
WHERE ST.classNo=CL.classNo
AND ST.classNo IN 
	(SELECT Cl.classNo
	FROM Student ST,Class CL
	WHERE ST.classNo=CL.classNo AND ST.studentName='刘晨'
	)
