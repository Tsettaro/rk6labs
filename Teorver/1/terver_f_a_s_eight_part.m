% Enter here
R1 = 9; G1 = 7; B1 = 8; sum1 = R1 + G1 + B1;
R2 = 6; G2 = 11; B2 = 6; sum2 = R2 + G2 + B2;
R3 = 5; G3 = 7; B3 = 7; sum3 = R3 + G3 + B3;

% LET'S PARTY
sum = sum1 + sum2 + sum3 + 1;
p = 1/sum; q = 1 - p;

% Task 4.1
a = 0:7;
b = 0:30;
c = 120:3:145;

figure(1);
z = expr(100, p, a);
plot(a, z ,"LineWidth",2), title("n = 100"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'4-1-1.png')

figure(2);
stairs(a, calc(z), "LineWidth",2), title("F(k) n = 100"), xlabel("k"), ylabel("F(k)");
grid on;
saveas(gcf,'4-1-2.png')

figure(3);
z = expr(1000, p, b);
plot(b,z ,"LineWidth",2), title("n = 1000"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'4-1-3.png')

figure(4);
stairs(b, calc(z), "LineWidth",2), title("F(k) n = 1000"), xlabel("k"), ylabel("F(k)");
grid on;
saveas(gcf,'4-1-4.png')

figure(5);
z = expr(10000, p, c);
plot(c,z ,"LineWidth",2), title("n = 10000"), xlabel("k"), ylabel("P(k)");
grid on
saveas(gcf,'4-1-5.png')

figure(6);
stairs(c, calc(z), "LineWidth",2), title("F(k) n = 10000"), xlabel("k"), ylabel("F(k)");
grid on;
saveas(gcf,'4-1-6.png')

% Task 4.2
syms n;
p = [0.7 0.8 0.9 0.95 0.99];
x = p - 0.5;
n_arr = [];
for i=p
    q = round(double(vpasolve(exp(-n*1/77) + n * 1/77 * exp(-n * 1/77) + (n*1/77)^(2)/2*exp(-n*1/77) == i, n)));
    n_arr = [n_arr q];
end

figure(7);
plot(p, n_arr, "LineWidth",2), title("P(k)"), xlabel("P(k)"), ylabel("n");
grid on;
saveas(gcf,'4-2-1.png')




function z = expr(n, p, K)
    z = [];
    for k = K
        l = n * p;
        x = l^(k)/fact(k) * exp(-l);
        z = [z x];
    end
end

function f = fact(k)
    f = factorial(k);
end

function F = calc(z)
    F = []; j = 0;
    for i=1:length(z)
        j = j + z(i);
        F = [F j];
    end
end