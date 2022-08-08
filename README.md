# PBL1
PBL1: Đồ án lập trình tính toán

# Tên đề tài C01: Đánh BOSS
Bạn đang chơi một trò chơi điện tử, trong đó bạn phải làm nhiệm vụ là đánh bại BOSS cuối để chiến thắng trò chơi. Bạn có thể thay phiên sử dụng N loại vũ khí khác nhau có trong túi, biết rằng mỗi món vũ khí có lượng sát thương riêng. BOSS có lượng máu là D, khi bạn sử dụng vũ khí có tính sát thương P tấn công BOSS thì máu của BOSS sẽ giảm đi một lượng là P (nếu D≤P thì D=0 bạn tiêu diệt được BOSS) và sau đó tính sát thương của món vũ khí đó sẽ giảm đi một nửa (lấy phần nguyên).
Bạn có thể thay đổi vũ khí tuỳ ý ở mỗi lần tấn công, tuy nhiên để tăng độ khó của trò chơi thì bạn chỉ được tấn công nhiều nhất là K lần. Nếu không thể tiêu diệt BOSS sau K lần thì bạn sẽ thua.

# Input
Dòng đầu chứa 3 số nguyên dương N(1 ≤ n ≤ 10^5), D(1 ≤ D ≤ 10^17), K(1 ≤ K ≤ 10^5).
Dòng tiếp theo chứ N số nguyên dương là độ sát thương của N món vũ khí bạn có trong túi.
  
# Output
In ra số lượng đợt tấn công ít nhất mà bạn có thể tiêu diệt được BOSS (nhỏ hơn hoặc bằng K), ngược lại in ra -1 nếu bạn không thể hạ BOSS sau nhiều nhất K lần tấn công.

# Ví dụ
  Input
3 30 7
10 5 13
  Output
4

# Giải thích
Có 3 món vũ khí trong túi (10, 5, 13).
Có thể tấn công như sau:
	Lần 1, chọn vũ khí đầu tiên, BOSS còn 20 máu và độ sát thương của vũ khí còn lại trong túi là (5, 5, 13).
	Lần 2, chọn vũ khí thứ ba, BOSS còn 7 máu và tập vũ khí (5, 5, 6).
	Lần 3, chọn vũ khí đầu tiên, BOSS còn 2 máu và tập vũ khí là (2, 5, 6).
	Lần 4, chọn vũ khí thứ ba, BOSS bị tiêu diệt do D<6 và tập vũ khí là (2, 5, 3).
Như vậy BOSS bị tiêu diệt sau 4 lần.
