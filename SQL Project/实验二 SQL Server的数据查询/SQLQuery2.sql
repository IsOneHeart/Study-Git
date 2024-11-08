--(13).查询至少选修了两门以上课程的学生的学号、姓名和所在班级。
SELECT ST.studentNo,ST.studentName,CL.ClassName
FROM Student ST
JOIN Class CL ON ST.classNo=CL.classNo
JOIN (
    SELECT SC.studentNo
    FROM Score SC
    GROUP BY SC.studentNo
    HAVING COUNT(SC.courseNo) >= 2
) AS SQ ON ST.studentNo = SQ.studentNo;