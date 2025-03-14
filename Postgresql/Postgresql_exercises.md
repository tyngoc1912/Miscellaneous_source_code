# Source Code
```sql
/*

YÊU CẦU

Để phân tích sâu hơn, Area Sales Manager cần lấy toàn bộ đơn hàng của bang LA. 
Đơn nào có doanh thu cao nhất thì xem trước.

*/

SELECT * 
FROM sales 
WHERE customer_state = 'LA'
ORDER BY net_sales DESC

/*

YÊU CẦU

Sales Supervisor cần xem đơn hàng của các thành phố Lincoln, Baton Rouge.

*/

SELECT *
FROM sales 
WHERE 
    customer_city = 'Lincoln' 
    OR customer_city = 'Baton Rouge'

/*

YÊU CẦU

Associate Brand Manager cần xem đơn hàng của các sản phẩm 175, 99.
Sắp xếp kết quả theo tên sản phẩm.

*/

SELECT *
FROM sales 
WHERE 
    sales_id = 175 
    OR sales_id = 99
ORDER BY product_name 

/*

YÊU CẦU

Xem đơn hàng của những khách có tên chứa chữ Davi.
Ví dụ: Connie Davis, Davin Stemm

*/

SELECT *
FROM sales 
WHERE customer_name LIKE '%Davi%'

/*

YÊU CẦU

Xem đơn hàng của những sản phẩm có tên bắt đầu bằng chữ Light hoặc Synergis.
Ví dụ: Synergistic Steel Chair, Lightweight Wool Plate.

*/

SELECT *
FROM sales 
WHERE 
    product_name LIKE 'Light%'
    OR product_name LIKE 'Synergis%'

/*

YÊU CẦU

Xem đơn hàng của những khách có tên kết thúc bằng chữ Walker hoặc King.
Ví dụ: Jewell Walker, Jerrod King.

*/

SELECT *
FROM sales 
WHERE 
    customer_name LIKE '%Walker'
    OR customer_name LIKE '%King'

/*

YÊU CẦU

Xem top 50 đơn hàng có doanh thu cao nhất của ngàng hàng Widget được 
giao đến bang New York.

*/

SELECT *
FROM sales 
WHERE 
    category = 'Widget'
    AND customer_state = 'NY'
ORDER BY net_sales DESC
LIMIT 50

/*

YÊU CẦU

Để lập kế hoạch phân phối, Sales Director muốn biết doanh thu theo từng thành phố.

*/

SELECT 
    customer_city
    , SUM(net_sales)
FROM sales 
GROUP BY customer_city

/*

YÊU CẦU

Để tính tiền bonus nhận từ nhà cung ứng, Purchasing cần báo cáo tổng 
doanh số (quantity), tổng doanh thu (net_sales) của từng sản phẩm. 

Kết quả cần hiện cả mã và tên sản phẩm.

*/

SELECT 
    product_id
    , product_name
    , SUM(quantity)
    , SUM(net_sales)
FROM sales  
GROUP BY 1, 2

/*

YÊU CẦU

Có bao nhiêu đơn có doanh thu trong khoảng từ $250 đến $750?

*/

SELECT
    COUNT(sales_id)
FROM sales 
WHERE net_sales BETWEEN 250 AND 750

/*

YÊU CẦU

Đơn hàng có doanh thu nhỏ nhất từ trước đến nay là bao nhiêu? 
(cần loại trừ các đơn có doanh thu nhỏ hơn hoặc bằng 0)

*/

SELECT
    MIN(net_sales)
FROM sales 
WHERE net_sales > 0

/*

YÊU CẦU

Purchasing Specialist tại chi nhánh NY cần báo cáo tổng doanh thu,
tổng doanh số của từng sản phẩm được bán tại bang New York.

*/

SELECT 
    product_id
    , product_name
    , SUM(net_sales)
    , SUM(quantity)
FROM sales  
WHERE customer_state = 'NY'
GROUP BY 1, 2

/*

YÊU CẦU

Để tặng voucher, team Customer Service cần báo cáo top 10 khách hàng mua nhiều đơn nhất.

*/

SELECT
    customer_id
    , customer_name
    , COUNT(sales_id)
FROM sales 
GROUP BY 1, 2
ORDER BY 3 DESC 
LIMIT 10

/*

YÊU CẦU

Để làm banner cho chương trình marketing sắp tới, team Designer cần danh sách top 20 sản phẩm mang lại nhiều doanh thu nhất tại bang Montana. 

*/

SELECT 
    product_id
    , product_name
    , SUM(net_sales)
FROM sales 
WHERE customer_state = 'MT'
GROUP BY 1, 2 
ORDER BY 3 DESC 
LIMIT 20

/*

YÊU CẦU

Chi nhánh tại bang Colorado đang cần phần tích tệp khách hàng tại Colorado. 
Lập báo cáo theo từng khách hàng sống tại Colorado, cần thể hiện các chỉ số bên dưới. 
- tổng chi tiêu
- tổng số đơn hàng đã mua
- tổng số lượng sản phẩm đã mua
- AOV
- giá trị đơn hàng lớn nhất từng mua
Sắp xếp theo tổng chi tiêu giảm dần.

*/

SELECT 
    customer_id
    , customer_name
    , SUM(net_sales)
    , COUNT(sales_id)
    , SUM(quantity)
    , AVG(net_sales)
    , MAX(net_sales)
FROM sales 
WHERE customer_state = 'CO' 
GROUP BY 1, 2
ORDER BY 3 DESC

/*

YÊU CẦU

Giám đốc Bán hàng đang lên chiến lược phân phối và cần một báo cáo chi tiết theo từng bang.
Lập báo cáo doanh thu của các bang, cần thể hiện các chỉ số sau:
- tổng doanh thu
- tổng doanh số
- tổng số đơn hàng đã bán
- AOV
Sắp xếp theo tổng doanh thu giảm dần.

*/

SELECT 
    customer_state
    , SUM(net_sales)
    , SUM(quantity)
    , COUNT(sales_id)
    , AVG(net_sales)
FROM sales 
GROUP BY 1
ORDER BY 2 DESC

/*

YÊU CẦU

Công ty đang cần phân tích hành vi khách hàng để tăng doanh thu. Kế hoạch 
sơ khởi bao gồm: 
- Phân nhóm đơn hàng dựa trên doanh số
- Giao kết quả cho team Marketing để chạy promotion
    - Đối với khách mua nhiều: Chương trình mua X tặng x cho sản phẩm A, 
      với A là sản phẩm cần đẩy mạnh doanh số.
    - Còn lại: Chương trình mua x sản phẩm B tặng x sản phẩm C, với B là 
      sản phẩm cần đẩy doanh số, C là sản phẩm tồn kho nhiều.

Theo kế hoạch đó, đầu tiên bạn cần phân nhóm đơn hàng thành các loại sau 
dựa trên doanh số: 
+ >= 10: High volume
+ Từ 2 đến 10: Normal volume
+ Từ 0 đến 2: Low volume

*/

SELECT 
    sales_id
    , quantity
    , CASE 
        WHEN quantity >= 10 THEN 'High volume'
        WHEN quantity >= 2 THEN 'Normal volume'
        WHEN quantity > 0 THEN 'Low volume'
        ELSE 'Undefined'
    END AS order_type 
FROM sales 

/*

YÊU CẦU

Công ty đang cần phân nhóm sản phẩm để thực hiện một số phân tích về 
sản phẩm. Bạn cần phân nhóm sản phẩm như yêu cầu bên dưới:
- Fashion: tên sản phẩm kết thúc bằng Watch, Hat, Wallet, Coat, Shoes, 
  Gloves, Bag, Shirt, Pants
- Home & Living: tên sản phẩm kết thúc bằng Bench, Table, Clock, Chair, 
  Lamp, Knife, Plate
- Others: còn lại

*/

SELECT
    sales_id
    , product_name
    , CASE 
        WHEN product_name LIKE '%Watch' THEN 'Fashion' 
        WHEN product_name LIKE '%Hat' THEN 'Fashion'
        WHEN product_name LIKE '%Wallet' THEN 'Fashion'
        WHEN product_name LIKE '%Coat' THEN 'Fashion' 
        WHEN product_name LIKE '%Shoes' THEN 'Fashion' 
        WHEN product_name LIKE '%Gloves' THEN 'Fashion' 
        WHEN product_name LIKE '%Bag' THEN 'Fashion' 
        WHEN product_name LIKE '%Shirt' THEN 'Fashion' 
        WHEN product_name LIKE '%Pants' THEN 'Fashion'
        WHEN product_name LIKE '%Bench' THEN 'Home & Living' 
        WHEN product_name LIKE '%Table' THEN 'Home & Living'
        WHEN product_name LIKE '%Clock' THEN 'Home & Living' 
        WHEN product_name LIKE '%Chair' THEN 'Home & Living' 
        WHEN product_name LIKE '%Lamp' THEN 'Home & Living'
        WHEN product_name LIKE '%Knife' THEN 'Home & Living' 
        WHEN product_name LIKE '%Plate' THEN 'Home & Living' 
        ELSE 'Others'
    END AS product_type 
FROM sales 

/*

YÊU CẦU

Team Marketing đang cần phân tích hành vi của những khách hàng có tổng 
chi tiêu trong khoảng $1000-$2000. 

Lập danh sách khách hàng theo như yêu cầu của team Marketing.

*/

WITH customer_revenue AS(
    SELECT
        customer_id
        , customer_name
        , SUM(net_sales) AS total
    FROM sales 
    GROUP BY 1, 2
)
SELECT
    *
FROM customer_revenue
WHERE total BETWEEN 1000 AND 2000

/*

YÊU CẦU

Giám đốc bán hàng đang cần phân bổ lại cấu trúc quản lý của Regional Sales Manager. 

Theo yêu cầu từ giám đốc bán hàng, bạn cần phân nhóm bang theo tổng doanh thu: 
- High value: >= $100,000
- Normal value: $50,000 - $100,000
- Low value: < $50,000

*/

WITH revenue AS(
    SELECT
        customer_state
        , SUM(net_sales) AS total
    FROM sales 
    GROUP BY 1
)
SELECT
    *
    , CASE 
        WHEN total >= 100000 THEN 'High value'
        WHEN total >= 50000 THEN 'Normal value'
        WHEN total > 0 THEN 'Low value'
        ELSE 'Undefined'
    END AS sales_segment
FROM revenue

/*

YÊU CẦU

Công ty đang cần phân tích hành vi khách hàng để tăng doanh thu. Kế hoạch 
sơ khởi bao gồm: 
- Phân nhóm đơn hàng dựa trên doanh số
- Giao kết quả cho team Marketing để chạy promotion
    - Đối với khách mua nhiều: Chương trình mua X tặng x cho sản phẩm A, 
      với A là sản phẩm cần đẩy mạnh doanh số.
    - Còn lại: Chương trình mua x sản phẩm B tặng x sản phẩm C, với B là 
      sản phẩm cần đẩy doanh số, C là sản phẩm tồn kho nhiều.

Cách phân nhóm đơn hàng, đã làm ở M03 - K01: 
+ >= 10: High volume
+ Từ 2 đến 10: Normal volume
+ Từ 0 đến 2: Low volume

Dựa trên kết quả đó, tính số lượng khách hàng của từng nhóm để công ty 
có thể dự tính số lượng promo code cần tung ra.

*/

WITH order_segment AS(
    SELECT 
        sales_id
        , customer_id
        , customer_name
        , quantity
        , CASE 
            WHEN quantity >= 10 THEN 'High volume'
            WHEN quantity >= 2 THEN 'Normal volume'
            WHEN quantity > 0 THEN 'Low volume'
            ELSE 'Undefined'
        END AS order_type 
    FROM sales 
)
SELECT 
    order_type
    , COUNT(DISTINCT customer_id)
FROM order_segment 
GROUP BY 1

/*

YÊU CẦU

Team Marketing đang cần phân nhóm khách hàng để thực hiện các chương trình 
marketing theo từng nhóm khách hàng.

Cách phân nhóm khách hàng theo tổng chi tiêu, đã làm ở M04 - T02: 
- High value: > $3000
- Normal value: $1000 - $3000
- Low value: < $1000

Dựa trên kết quả đó, tính số lượng khách hàng, tổng chi tiêu của từng nhóm 
khách hàng.

*/

WITH revenue AS(
    SELECT 
        customer_id
        , customer_name
        , SUM(net_sales) AS total
    FROM sales
    GROUP BY 1, 2
)
, customer_segment AS(
    SELECT
        *
        , CASE 
            WHEN total > 3000 THEN 'High value'
            WHEN total >= 1000 THEN 'Normal value'
            WHEN total > 0 THEN 'Low value'
            ELSE 'Undefined'
        END AS customer_type
    FROM revenue
)
SELECT 
    customer_type
    , COUNT(DISTINCT customer_id)
    , SUM(total)
FROM customer_segment
GROUP BY 1

/*

YÊU CẦU

Financial Analyst cần báo cáo tổng doanh thu của từng bang trong khoảng 
từ tháng 04/2018 đến hết tháng 03/2019.

*/

SELECT 
    customer_state
    , SUM(net_sales) AS total 
FROM sales 
WHERE 
    --created_at BETWEEN '2018-04-01' AND '2019-04-01'
    created_at >= '2018-04-01'
    AND DATE_TRUNC('DAY', created_at) <= '2019-03-31'
GROUP BY 1

/*

YÊU CẦU

Team Purchasing đang lên kế hoạch tìm nguồn hàng mới và cần hiểu sự thay đổi thị hiếu 
mua hàng qua từng năm. 

Để làm được, bạn cần làm tổng hợp các chỉ số bên dưới theo từng sản phẩm qua từng năm:
- tổng doanh thu
- tổng doanh số
- tổng số đơn hàng đã bán
- AOV

Sắp xếp theo từng sản phẩm, sau đó theo thời gian để team Purchasing dễ theo dõi.

*/

SELECT
    product_id
    , product_name
    , TO_CHAR(created_at, 'YYYY')
    , SUM(net_sales)
    , SUM(quantity)
    , COUNT(sales_id)
    , AVG(net_sales)
FROM sales 
GROUP BY 1, 2, 3
ORDER BY 1, 3

/*

YÊU CẦU

Team Marketing muốn xuất một báo cáo doanh thu, doanh số theo tháng. 

Tuy nhiên, team Marketing yêu cầu cột tháng phải theo format chuẩn. 
Ví dụ Jan 2019, Feb 2019,...

*/

SELECT 
    TO_CHAR(created_at, 'Mon YYYY')
    , DATE_TRUNC('MONTH', ctreated_at)
    , SUM(net_sales)
    , SUM(quantity)
FROM sales 
GROUP BY 1, 2
ORDER BY 2

/*

YÊU CẦU

Team Sales có một target bán hàng theo nửa năm. 

Bạn hãy giúp team sales làm một báo cáo doanh thu, doanh số theo 
nửa năm (haft year). Ví dụ: 2018-H1, 2018-H2, 2019-H1,...

*/

SELECT
    CASE 
        WHEN EXTRACT(QUARTER FROM created_at) IN(1, 2) THEN TO_CHAR(created_at, 'YYYY-H1') 
        WHEN EXTRACT(QUARTER FROM created_at) IN(3, 4) THEN TO_CHAR(created_at, 'YYYY-H2')
    END AS half_year
    , SUM(net_sales)
    , SUM(quantity)
FROM sales 
GROUP BY 1

/*

YÊU CẦU

Sales Supervisor cần xem data thô đơn hàng của các thành phố South Fulton, East Prairie.

*/

SELECT 
    s.*
    , c.customer_city
FROM sales s
LEFT JOIN customer c USING(customer_id)
WHERE c.customer_city IN ('South Fulton', 'East Prairie')

/*

YÊU CẦU

Xem top 50 đơn hàng có doanh thu cao nhất của ngàng hàng Gadget được giao 
đến bang Colorado.

*/

SELECT 
    s.sales_id
    , c.customer_state
    , P.category
    , s.net_sales
FROM sales s
LEFT JOIN customer c USING(customer_id)
LEFT JOIN product p USING(product_id)
WHERE 
    p.category = 'Gadget'
    AND c.customer_state = 'CO'
ORDER BY s.net_sales DESC 
LIMIT 50

/*

YÊU CẦU

Purchasing Specialist tại chi nhánh bang Alabama cần báo cáo tổng doanh thu, 
tổng doanh số của từng sản phẩm được bán tại bang.

*/

SELECT 
    p.product_id
    , c.customer_state
    , SUM(s.net_sales)
    , SUM(s.quantity)
FROM sales s
LEFT JOIN customer c USING(customer_id)
LEFT JOIN product p USING(product_id)
WHERE c.customer_state = 'AL'
GROUP BY 1, 2

/*

YÊU CẦU

Để đánh giá KPI của kênh bán hàng qua thời gian, Marketing Director 
cần báo cáo doanh thu theo từng quý từng source (customer_source). 

Tuy nhiên, các source Facebook, Twitter cần gom lại thành Social. 
Google đổi tên thành Search Engine.

Ngoài ra, Marketing Director cần dàn source theo từng cột. Mỗi cột 
là một source, mỗi dòng là một quý. 

Sắp xếp theo quý, và theo source.

*/

WITH source AS(
    SELECT 
        *
        , CASE 
            WHEN customer_source IN('Facebook', 'Twitter') THEN 'Social'
            WHEN customer_source = 'Google' THEN 'Search Engine'
            ELSE customer_source
        END AS new_source
    FROM customer 
)
SELECT 
    TO_CHAR(created_at, 'Q - YYYY') AS "Quarter-Year"
    , SUM(CASE WHEN source.new_source = 'Affiliate' THEN sales.net_sales END) AS "Affiliate"
    , SUM(CASE WHEN source.new_source = 'Organic' THEN sales.net_sales END) AS "Organic"
    , SUM(CASE WHEN source.new_source = 'Social' THEN sales.net_sales END) AS "Social"
    , SUM(CASE WHEN source.new_source = 'Search Engine' THEN sales.net_sales END) AS "Search Engine"
FROM sales 
LEFT JOIN source USING(customer_id) 
GROUP BY 1
ORDER BY 1

/*

YÊU CẦU

Mỗi năm công ty đều trao quà cho “Top 20 khách hàng chi tiêu nhiều nhất” 
trong năm trước. Xem thông tin của các khách hàng từng lọt “Top 20 Khách 
hàng chi tiêu nhiều nhất” trong các năm từ 2017 đến 2019.

*/

WITH revenue_2017 AS(
    SELECT 
        c.customer_id
        , SUM(s.net_sales)
    FROM sales s
    LEFT JOIN customer c USING(customer_id)
    WHERE EXTRACT(YEAR FROM created_at) = '2017'
    GROUP BY 1
    ORDER BY 2 DESC 
    LIMIT 20 
)
, revenue_2018 AS(
    SELECT 
        c.customer_id
        , SUM(s.net_sales)
    FROM sales s
    LEFT JOIN customer c USING(customer_id)
    WHERE EXTRACT(YEAR FROM created_at) = '2018'
    GROUP BY 1
    ORDER BY 2 DESC 
    LIMIT 20 
)
, revenue_2019 AS(
    SELECT 
        c.customer_id
        , SUM(s.net_sales)
    FROM sales s
    LEFT JOIN customer c USING(customer_id)
    WHERE EXTRACT(YEAR FROM created_at) = '2019'
    GROUP BY 1
    ORDER BY 2 DESC 
    LIMIT 20 
)
SELECT *
FROM customer
WHERE 
    customer_id IN(SELECT customer_id FROM revenue_2017)
    OR customer_id IN(SELECT customer_id FROM revenue_2018)
    OR customer_id IN(SELECT customer_id FROM revenue_2019)

/*

YÊU CẦU

Công ty đang muốn tăng doanh thu tại các thị trường mới. Để làm việc đó, 
công ty muốn hiểu được hành vi mua hàng của các bang có doanh thu tốt, 
và sự khác biệt với các bang còn lại.

Dựa theo kế hoạch đó, đầu tiên bạn cần phân nhóm bang theo doanh thu: 
- Big 5: top 5 bang có doanh thu cao nhất từ trước đến nay
- Big 10: top 5 bang kế tiếp sau Big 5
- Big 15: top 5 bang kế tiếp sau Big 10
- Others: Các bang còn lại

*/

WITH revenue AS(
    SELECT 
        c.customer_state
        , SUM(s.net_sales)
    FROM sales s
    LEFT JOIN customer c USING(customer_id)
    GROUP BY 1 
    ORDER BY 2 DESC 
)
SELECT
    *
    , CASE
        WHEN customer_state IN (SELECT customer_state FROM revenue LIMIT 5) THEN 'Big 5'
        WHEN customer_state IN (SELECT customer_state FROM revenue LIMIT 10) THEN 'Big 10'
        WHEN customer_state IN (SELECT customer_state FROM revenue LIMIT 15) THEN 'Big 15'
        ELSE THEN 'Others'
    END AS state_segment
FROM customer

/*

YÊU CẦU

Sales Director cần một báo cáo tổng doanh thu của từng bang trong năm 2019. 

Tuy nhiên vì kết quả khá dài nên Sales Director cần thêm một cột STT (số 
thứ tự) để thể hiện xếp hạng doanh thu của từng bang (ví dụ bang nào cao 
nhất sẽ có STT là 1, tiếp theo là 2…).

*/

WITH state_revenue AS(
    SELECT
        c.customer_state
        , SUM(s.net_sales) AS net_sales
    FROM sales s
    LEFT JOIN customer c USING(customer_id)
    WHERE EXTRACT(YEAR FROM created_at) = 2019
    GROUP BY 1
)
SELECT
    *
    , RANK() OVER(ORDER BY net_sales DESC) AS ranking
FROM state_revenue

/*

YÊU CẦU

Team Customer Service vào mỗi tháng đều cần danh sách top khách hàng chi 
tiêu nhiều nhất. Tuy nhiên, Customer Service có lúc sẽ cần top 10, có 
lúc cần top 20… Bạn hãy tạo một báo cáo để hỗ trợ nhu cầu trên một cách 
thông minh.

*/

WITH customer_revenue AS(
    SELECT
        DATE_TRUNC('MONTH', s.created_at) AS created_month
        , c.customer_id
        , c.customer_name
        , SUM(s.net_sales) AS net_sales
    FROM sales s
    LEFT JOIN customer c USING(c.customer_id)
    GROUP BY 1, 2, 3
    ORDER BY 1, 4 DESC
)
SELECT
    *
    , RANK() OVER(PARTITION BY created_month ORDER BY net_sales) AS ranking
FROM customer_revenue

/*

YÊU CẦU

Tính doanh thu lũy kế (cumulative sum/running total) qua từng tháng của công ty.

*/

WITH by_month AS(
    SELECT
        DATE_TRUNC('MONTH', created_at) AS created_month
        , SUM(net_sales) AS net_sales
    FROM sales
    GROUP BY 1
)
SELECT 
    *
    , SUM(net_sales) OVER(ORDER BY created_at) AS cummulative_sum -- cộng từ dòng đầu tiên đến dòng hiện tại
FROM by_month
ORDER BY 1

/*

YÊU CẦU

Trụ sở chính chuẩn bị chạy chương trình trao quà tri ân cho khách hàng của mỗi bang. 

Để phục vụ chương trình này, lập danh sách top 20 khách hàng chi tiêu nhiều nhất của mỗi bang.

*/

WITH by_customer AS(
    SELECT
        c.customer_state
        , c.customer_id
        , c.customer_name
        , SUM(net_sales) AS total
    FROM sales s
    JOIN customer c USING(customer_id)
    GROUP BY 1, 2, 3
)
, by_state AS(
    SELECT 
        *
        , RANK() OVER(PARTITION BY customer_state ORDER BY total DESC) AS state_ranking
    FROM by_customer
    ORDER BY 1, 4 DESC
)
SELECT *
FROM by_customer
WHERE state_ranking <= 20

/*

YÊU CẦU

Team Marketing đang nghiên cứu các nhân tố làm cho khách hàng chi tiêu 
nhiều hơn/ít hơn.

Bạn hãy hỗ trợ team Marketing làm một báo cáo doanh thu theo từng khách 
theo từng năm. Sau đó làm thêm một cột doanh thu của 1 năm trước đó và 
phân nhóm là tăng nhiều (tăng hơn $500) hoặc giảm nhiều (giảm hơn $500) 
hoặc không thay đổi nhiều (còn lại).

Gợi ý: Tìm hiểu về hàm LAG

Kết quả mẫu như bên dưới: 
| customer_id | customer_name | year | spent_amount | last_year_spent_amount | yoy_change | yoy_segment |
|-------------|---------------|------|--------------|------------------------|------------|-------------|
| 1           | John          | 2018 | $4000        | -                      | -          | No change   |
| 1           | John          | 2019 | $6000        | $4000                  | 2000       | Increase    |
| 1           | John          | 2020 | $2000        | $6000                  | -4000      | Decrease    |

*/

WITH customer_over_year AS (
    SELECT 
        sales.customer_id
        , customer.customer_name
        , EXTRACT(YEAR FROM created_at) AS year
        , SUM(sales.net_sales) AS spent_amount 
    FROM sales 
    LEFT JOIN customer ON sales.customer_id = customer.customer_id 
    GROUP BY 1, 2, 3
)

, calculate_last_year AS (
    SELECT
        *
        , LAG(spent_amount, 1) OVER (PARTITION BY customer_id ORDER BY year) AS last_year_spent_amount
        , spent_amount - LAG(spent_amount, 1) OVER (PARTITION BY customer_id ORDER BY year) AS yoy_change
    FROM customer_over_year 
)

SELECT
    *
    , CASE 
        WHEN yoy_change >= 500 THEN 'Increase'
        WHEN yoy_change <= -500 THEN 'Decrease'
        ELSE 'No change' END
    AS yoy_segment
FROM calculate_last_year
```
