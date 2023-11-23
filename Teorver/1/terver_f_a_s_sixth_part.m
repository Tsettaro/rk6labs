% Enter here
R2 = 6; G2 = 11; B2 = 6; sum = R2 + G2 + B2;

% LET'S PARTY
n = G2 + B2;
%Task 2.1 and 2.2

p = [];
kk = 0:R2;
for k=0:R2
    temp = calculate_c(n, k) * (fact(n) * fact(R2) * fact(sum - n)); %PROOF THIS
    temp = temp/(fact(k)*fact(R2-k)*fact(sum));
    p = [p temp];
end

F = []; i = 0;
for j=1:length(p)
    i = i + p(j);
    F = [F i];
end

figure(1);
scatter(kk,p, "filled", "blue"), xlabel("k"), ylabel("P(k)"), title("P(k)");
grid on;
saveas(gcf,'2-1-1.png')

figure(2);
stairs(0:length(p)-1, F, "LineWidth",2), xlabel("k"), ylabel("F(k)"), title("F(k)");
grid on;
saveas(gcf,'2-2-1.png')

%Task 2.3 and 2.4
M1 = 0; M2 = 0;
for i=1:length(p)
    M1 = M1 + p(i) * kk(i); % you need this
    M2 = M2 + kk(i)^(2) * p(i);
end
D = M2 - M1^(2);

function r = calculate_c(n, k)
   r = fact(n)/(fact(k)*fact(n-k));
end

function f = fact(k)
    f = factorial(k);
end