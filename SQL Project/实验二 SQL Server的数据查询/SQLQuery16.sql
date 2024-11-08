--(23).通过视图studentScore查询最高成绩在90分及以上(含90分)且没有不及格成绩的学生学号、姓名、所属学院、班级。
SELECT DISTINCT SS.学号 学号,SS.姓名 姓名,CL.institute 所属学院,CL.className 班级
FROM studentScore SS,Class CL,Student ST
WHERE SS.最高成绩>=90 AND SS.最低成绩>=60
	AND SS.学号=ST.studentNo AND ST.classNo=CL.classNo