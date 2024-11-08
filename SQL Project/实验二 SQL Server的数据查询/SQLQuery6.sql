--查询选修学生人数少于6人的课程名称。
SELECT CO.courseName
FROM (SELECT CO.courseName,COUNT(SC.studentNo) 人数
	FROM Course CO,Score SC
	WHERE CO.courseNo=SC.courseNo
	GROUP BY CO.courseNo,CO.courseName
	) AS CO
WHERE CO.人数<6
