--(22).定义一个查询学生的学号、姓名、学期、最高成绩、最低成绩、平均成绩的视图studentScore。
CREATE VIEW studentScore AS
SELECT ST.studentNo 学号,ST.studentName 姓名,TE.termName 学期,
		MAX(SC.score) 最高成绩,MIN(SC.score)最低成绩,AVG(SC.score)平均成绩
FROM Student ST,Score SC,Term TE
WHERE ST.studentNo=SC.studentNo AND SC.termNo=TE.termNo
GROUP BY ST.studentNo,ST.studentName,TE.termName