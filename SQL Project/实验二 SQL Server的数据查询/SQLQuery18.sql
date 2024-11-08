--(25).将注册会计16_01班的女同学的成绩都增加10分。
UPDATE Score
SET score+=10
WHERE studentNo IN (SELECT ST.studentNo
	FROM Student ST,Class CL
	WHERE CL.classNo=ST.classNo
	AND CL.className='注册会计16_01班'
	AND ST.sex='女')