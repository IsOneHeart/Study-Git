--查询“IS1501”班同学选修的课程名称
SELECT DISTINCT CO.courseName
FROM Course CO,(SELECT SC.courseNo
	FROM Score SC,Student ST,Class CL
	WHERE SC.studentNo=ST.studentNo
	AND ST.classNo=CL.classNo AND CL.classNo='IS1501') COE
WHERE CO.courseNo=COE.courseNo