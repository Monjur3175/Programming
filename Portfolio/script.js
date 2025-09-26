// Add smooth scrolling for navigation
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();
        document.querySelector(this.getAttribute('href')).scrollIntoView({
            behavior: 'smooth'
        });
    });
});

// Add animation on scroll
const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            entry.target.classList.add('show');
        }
    });
}, {
    threshold: 0.1
});

document.querySelectorAll('.card, .skill, .interest, .fade-in').forEach((el) => observer.observe(el));

// Typing effect for header
const typeWriter = (text, element, speed = 100) => {
    let i = 0;
    element.innerHTML = '';
    const type = () => {
        if (i < text.length) {
            element.innerHTML += text.charAt(i);
            i++;
            setTimeout(type, speed);
        }
    };
    type();
};

// Typing animation
const typingText = document.querySelector('.typing-text');
if (typingText) {
    const text = typingText.textContent;
    typingText.textContent = '';

    let charIndex = 0;
    function type() {
        if (charIndex < text.length) {
            typingText.textContent += text.charAt(charIndex);
            charIndex++;
            setTimeout(type, 100);
        } else {
            setTimeout(resetTyping, 3000);
        }
    }

    function resetTyping() {
        charIndex = 0;
        typingText.textContent = '';
        setTimeout(type, 500);
    }

    // Start typing animation
    setTimeout(type, 1000);
}

// Dark mode toggle
const toggleDarkMode = () => {
    document.body.classList.toggle('dark-mode');
    const isDarkMode = document.body.classList.contains('dark-mode');
    localStorage.setItem('darkMode', isDarkMode);
};

// Initialize dark mode based on user preference
if (localStorage.getItem('darkMode') === 'true') {
    document.body.classList.add('dark-mode');
}

// Particle background
const createParticles = () => {
    const particlesContainer = document.getElementById('particles');
    if (!particlesContainer) return;
    for (let i = 0; i < 50; i++) {
        const particle = document.createElement('div');
        particle.className = 'particle';
        particle.style.left = Math.random() * 100 + 'vw';
        particle.style.animationDuration = (Math.random() * 3 + 2) + 's';
        particle.style.animationDelay = Math.random() * 2 + 's';
        particlesContainer.appendChild(particle);
    }
};

// Initialize particles
window.addEventListener('load', createParticles);

// Navbar scroll color behavior
const nav = document.querySelector('nav.site-nav');
const onScroll = () => {
    if (!nav) return;
    const scrolled = window.scrollY > 10;
    nav.classList.toggle('scrolled', scrolled);
};
window.addEventListener('scroll', onScroll);
onScroll();

// Kebab menu toggle
const navToggle = document.getElementById('nav-toggle');
const navMenu = document.querySelector('.site-nav .menu');
if (navToggle && navMenu) {
    navToggle.addEventListener('click', () => {
        navMenu.classList.toggle('open');
    });
}
