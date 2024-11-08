--(24).删除平均分在75到80分之间的同学的选课记录。
DELETE FROM Score
WHERE studentNo IN (SELECT studentNo FROM Score
	GROUP BY studentNo HAVING AVG(score) BETWEEN 75 AND 80)