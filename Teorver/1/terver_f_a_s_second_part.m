% Enter here
R1 = 9; G1 = 7; B1 = 8; sum = R1 + G1 + B1;

% LET'S PARTY
p= R1/sum; q = 1-p;

%Task 1.3
a = 0:18;
b = 5:30;
c = 20:55;
d = 50:100;
e = 120:3:180;
f = 321:3:430;

figure(1);
z = expr(25, p, q, a);
plot(a, z ,'LineWidth',2), title("n = 25"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'1-3-1.png')

figure(2);
z = expr(50, p, q, b);
plot(b, z,"LineWidth",2), title("n = 50"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'1-3-2.png')


figure(3);
z = expr(100, p, q, c);
plot(c, z ,"LineWidth",2), title("n = 100"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'1-3-3.png')


figure(4);
z = expr(200, p, q, d);
plot(d, z ,"LineWidth",2), title("n = 200"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'1-3-4.png')


figure(5);
z = expr(400, p, q, e);
plot(e, z ,"LineWidth",2), title("n = 400"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'1-3-5.png')


figure(6);
z = expr(1000, p, q, f);
plot(f, z ,"LineWidth",2), title("n = 1000"), xlabel("k"), ylabel("P(k)");
grid on;
saveas(gcf,'1-3-6.png')

function z = expr(n, p, q, K)
    z = [];
    for k = K
        x = calculate(k, n, p, q);
        pn = phi(x)/sqrt(n*p*q);
        z = [z pn];
    end
end

function x = calculate(k, n, p, q)
    x = (k - n*p)/sqrt(n*p*q);
end

function r = phi(x)
   r = 1/(sqrt(2*pi)) * exp(-x^(2)/2);
end