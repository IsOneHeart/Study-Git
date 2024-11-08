--(12).查询至少有两门课程的成绩在80分以上学生的学号和成绩。
SELECT ST.studentNo, SC.score
FROM Student ST
JOIN Score SC ON ST.studentNo = SC.studentNo
WHERE SC.score > 80 AND ST.studentNo IN (
    SELECT studentNo
    FROM Score
    WHERE score > 80
    GROUP BY studentNo
    HAVING COUNT(*) >= 2
);
