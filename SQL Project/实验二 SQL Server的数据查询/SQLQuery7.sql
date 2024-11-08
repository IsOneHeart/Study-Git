--(18).查询成绩低于该门课程的平均分的学生的学号。
SELECT SC.studentNo
FROM Score SC,(SELECT AVG(SC.score) 平均分,SC.courseNo
	FROM Score SC
	GROUP BY SC.courseNo) AS SCA
WHERE SC.courseNo=SCA.courseNo
AND SC.score<SCA.平均分