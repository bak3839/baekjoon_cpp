-- 코드를 입력하세요
SELECT R.FLAVOR
FROM (
    SELECT FH.FLAVOR, SUM(FH.TOTAL_ORDER + J.TOTAL_ORDER) AS TOTAL
    FROM FIRST_HALF FH LEFT JOIN JULY J ON FH.FLAVOR = J.FLAVOR
    GROUP BY FH.FLAVOR
    ORDER BY TOTAL DESC
    LIMIT 3
) AS R