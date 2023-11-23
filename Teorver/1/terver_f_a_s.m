% Enter here
R1 = 9; G1 = 7; B1 = 8; sum = R1 + G1 + B1;

% LET'S PARTY
p = R1/sum; q = 1-p;
one = []; two = []; three = [];

%Task 1.1 and 1.2
for n = [6 9 12]
    i = 1;
    temp = [];
    for k = 0:1:n
        r = p^k * calculate_c(n, k) * q^(n-k);
        temp(i) = r;
        i = i+1;
    end
    if n == 6
        one = [one temp];
    elseif n == 9
        two = [two temp];
    else
        three = [three temp];
    end
end

F = []; i = 0;
for j=1:length(three)
    i = i + three(j);
    F = [F i];
end

figure(1);
scatter(0:6,one,"filled", "blue"), title("n = 6"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'1-1-1.png')

figure(2);
scatter(0:1:9,two,"filled", "blue"), title("n = 9"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'1-1-2.png')

figure(3);
scatter(0:12,three,"filled", "blue"), title("n = 12"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'1-1-3.png')

figure(4);
stairs(0:n,F,'LineWidth', 2), title("F(k) n = 12"), xlabel("k"), ylabel("F(k)"); % WARNING
grid on;
saveas(gcf,'1-2-1.png')


function r = calculate_c(n, k)
   r = factorial(n)/(factorial(k)*factorial(n-k));
end
