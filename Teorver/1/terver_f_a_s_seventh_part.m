% Enter here
R3 = 5; G3 = 5; B3 = 7; 

% LET'S PARTY
sum = R3 + G3 + B3;
%Task 3.1
p = [];
kk = R3:sum;
for i=kk
    temp = calculate_c(i-1, R3-1)/calculate_c(sum, R3);
    p = [p temp];
end

figure(1);
scatter(kk, p, "filled", "blue"), title("P(k)"), xlabel("k"), ylabel("P(k)"); 
grid on;
saveas(gcf,'3-1-1.png')


% Task 3.2
F = []; j = 0;
for i=1:length(kk)
    j = j + p(i);
    F = [F j];
end

figure(2);
stairs(kk, F, "LineWidth",2), title("F(k)"), xlabel("k"), ylabel("F(k)");
grid on;
saveas(gcf,'3-2-1.png')

% Task 3.3 and 3.4

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