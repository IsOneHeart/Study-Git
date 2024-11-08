--(20).查询至少选修两门以上课程（包括两门）的学生学号。
SELECT ST.studentNo
FROM Student ST
EXCEPT
SELECT ST.studentNo
FROM Student ST,Score SC
WHERE ST.studentNo=SC.studentNo
GROUP BY ST.studentNo
HAVING COUNT(*)<2