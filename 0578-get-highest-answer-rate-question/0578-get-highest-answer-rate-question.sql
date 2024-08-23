# Write your MySQL query statement below

select question_id as survey_log 
from SurveyLog
group by 1
order by sum(action = 'answer') / sum(action = 'show') desc, 1
limit 1;

