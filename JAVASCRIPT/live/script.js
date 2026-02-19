const typingText = document.getElementById("typingText");
const yesBtn = document.getElementById("yesBtn");
const noBtn = document.getElementById("noBtn");
const result = document.getElementById("result");
const countdown = document.getElementById("countdown");

// ======= Customize Names =======
document.getElementById("myName").innerText = "Harsh";
document.getElementById("herName").innerText = "My Love";
document.getElementById("herName2").innerText = "My Love";

/* Typing love letter */
const message = "From the moment you entered my life, everything started feeling magical. Your smile is my peace, your happiness is my dream, and your love is my world. ❤️";
let i = 0;

function typeEffect() {
  if (i < message.length) {
    typingText.innerHTML += message.charAt(i);
    i++;
    setTimeout(typeEffect, 40);
  }
}

typeEffect();

/* YES celebration */
yesBtn.addEventListener("click", () => {
  result.classList.remove("hidden");
  result.innerText = "Yaaay! You just made me the luckiest person alive ❤️✨";
});

/* NO button escape */
noBtn.addEventListener("mouseover", () => {
  const x = Math.random() * (window.innerWidth - 100);
  const y = Math.random() * (window.innerHeight - 50);
  noBtn.style.position = "fixed";
  noBtn.style.left = x + "px";
  noBtn.style.top = y + "px";
});

/* Floating hearts generator */
function createHeart() {
  const heart = document.createElement("div");
  heart.className = "heart";
  heart.innerText = "❤️";

  heart.style.left = Math.random() * 100 + "vw";
  heart.style.animationDuration = 4 + Math.random() * 4 + "s";

  document.body.appendChild(heart);

  setTimeout(() => heart.remove(), 8000);
}

setInterval(createHeart, 500);

/* Countdown to Valentine */
const valentine = new Date("Feb 14, 2026 00:00:00").getTime();

setInterval(() => {
  const now = new Date().getTime();
  const diff = valentine - now;

  if (diff <= 0) {
    countdown.innerText = "Happy Valentine's Day My Love ❤️";
    return;
  }

  const d = Math.floor(diff / (1000 * 60 * 60 * 24));
  const h = Math.floor((diff % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));

  countdown.innerText = `${d} days ${h} hours left for our special day ❤️`;
}, 1000);
