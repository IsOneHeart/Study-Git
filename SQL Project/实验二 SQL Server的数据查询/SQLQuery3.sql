--(14).查询所有学生（包括未选课的学生）的学号、姓名（SName）及该学生所选课程的平均分。提示：用外连接
SELECT ST.studentNo, ST.studentName, AVG(SC.score) AS 平均分
FROM Student ST
LEFT JOIN Score SC ON SC.studentNo = ST.studentNo
GROUP BY ST.studentNo, ST.studentName;
