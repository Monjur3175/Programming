// =========================================================
// ULTRA-FUTURISTIC AI ENGINEER PORTFOLIO JAVASCRIPT
// 1. Neural Network Synapse Canvas (Interactive AI Network)
// 2. 3D Card Perspective Tilt Tracking
// 3. NeuroCore Copilot Streamer
// 4. Dark Mode & Hamburger Toggle
// =========================================================

// --- 1. NEURAL SYNAPSE CANVAS SIMULATION ---
(function initNeuralCanvas() {
    const canvas = document.createElement('canvas');
    canvas.id = 'neural-canvas';
    document.body.prepend(canvas);

    const ctx = canvas.getContext('2d');
    let width = canvas.width = window.innerWidth;
    let height = canvas.height = window.innerHeight;

    window.addEventListener('resize', () => {
        width = canvas.width = window.innerWidth;
        height = canvas.height = window.innerHeight;
        initNodes();
    });

    const mouse = { x: -1000, y: -1000, active: false };
    window.addEventListener('mousemove', (e) => {
        mouse.x = e.clientX;
        mouse.y = e.clientY;
        mouse.active = true;
    });
    window.addEventListener('mouseout', () => {
        mouse.active = false;
    });

    let nodes = [];
    const NODE_COUNT = Math.min(Math.floor((width * height) / 18000), 75);

    function initNodes() {
        nodes = [];
        for (let i = 0; i < NODE_COUNT; i++) {
            nodes.push({
                x: Math.random() * width,
                y: Math.random() * height,
                vx: (Math.random() - 0.5) * 0.7,
                vy: (Math.random() - 0.5) * 0.7,
                radius: Math.random() * 2 + 1.5,
                activation: 0
            });
        }
    }
    initNodes();

    function render() {
        ctx.clearRect(0, 0, width, height);

        const isDark = document.body.classList.contains('dark-mode');
        const accent = getComputedStyle(document.body).getPropertyValue('--secondary-color').trim() || '#00f0ff';

        // Update & draw nodes
        for (let i = 0; i < nodes.length; i++) {
            const n = nodes[i];
            n.x += n.vx;
            n.y += n.vy;

            if (n.x < 0 || n.x > width) n.vx *= -1;
            if (n.y < 0 || n.y > height) n.vy *= -1;

            // Distance to mouse (simulated activation pulse)
            const dx = mouse.x - n.x;
            const dy = mouse.y - n.y;
            const dist = Math.sqrt(dx * dx + dy * dy);
            if (mouse.active && dist < 160) {
                n.activation = Math.min(n.activation + 0.08, 1);
            } else {
                n.activation = Math.max(n.activation - 0.02, 0);
            }

            // Draw neuron
            ctx.beginPath();
            ctx.arc(n.x, n.y, n.radius + (n.activation * 3), 0, Math.PI * 2);
            ctx.fillStyle = n.activation > 0.1 ? accent : (isDark ? 'rgba(255,255,255,0.4)' : 'rgba(0,0,0,0.25)');
            ctx.shadowBlur = n.activation * 12;
            ctx.shadowColor = accent;
            ctx.fill();
            ctx.shadowBlur = 0;

            // Connect synapses
            for (let j = i + 1; j < nodes.length; j++) {
                const n2 = nodes[j];
                const dxx = n.x - n2.x;
                const dyy = n.y - n2.y;
                const d = Math.sqrt(dxx * dxx + dyy * dyy);

                if (d < 130) {
                    const alpha = (1 - d / 130) * (0.2 + (n.activation + n2.activation) * 0.5);
                    ctx.beginPath();
                    ctx.moveTo(n.x, n.y);
                    ctx.lineTo(n2.x, n2.y);
                    ctx.strokeStyle = (n.activation > 0.2 || n2.activation > 0.2)
                        ? accent
                        : (isDark ? 'rgba(148, 163, 184, 0.18)' : 'rgba(15, 23, 42, 0.1)');
                    ctx.lineWidth = (n.activation > 0.2) ? 1.5 : 0.8;
                    ctx.globalAlpha = alpha;
                    ctx.stroke();
                    ctx.globalAlpha = 1;
                }
            }
        }

        requestAnimationFrame(render);
    }
    render();
})();

// --- 2. 3D CARD PERSPECTIVE TILT EFFECT ---
(function init3DCardTilt() {
    const cards = document.querySelectorAll('.card, .skill');

    cards.forEach(card => {
        card.addEventListener('mousemove', (e) => {
            const rect = card.getBoundingClientRect();
            const x = e.clientX - rect.left;
            const y = e.clientY - rect.top;

            const centerX = rect.width / 2;
            const centerY = rect.height / 2;

            const rotateX = ((y - centerY) / centerY) * -7;
            const rotateY = ((x - centerX) / centerX) * 7;

            card.style.transform = `perspective(1000px) rotateX(${rotateX.toFixed(2)}deg) rotateY(${rotateY.toFixed(2)}deg) translateY(-4px)`;
        });

        card.addEventListener('mouseleave', () => {
            card.style.transform = 'perspective(1000px) rotateX(0deg) rotateY(0deg) translateY(0)';
        });
    });
})();

// --- 3. RESEARCH PAPER ABSTRACT INSPECTOR HUD ---
const PAPERS_DATA = {
    manifold: {
        title: "Manifold Learning-Based Prediction and Stability Analysis of Lentil (Lens culinaris Medik.) Grain Yield Across Multiple Environments in Drought Condition",
        badge: "Journal — Preprint",
        metrics: "Ridge Regression Test R² = 0.8072 | RMSE = 183.77 kg/ha | Nested CV R² = 0.7289 | Top SHAP Predictors: DF_BP_Interaction & TSW | Stable Genotypes: G71 & G63",
        abstract: "Accurate prediction of lentil (Lens culinaris Medik.) grain yield in diverse environments is challenging because of complex genotype × environment interactions and nonlinear relationships among agronomic traits. This study proposes a framework integrating manifold learning, machine learning, explainable artificial intelligence (XAI), and genotype stability analysis for the assessment of lentil yield performance in drought-prone conditions in the northern region of Bangladesh. Engineered agromorphological trait analysis was performed on a 150-observation dataset on ten lentil genotypes grown in five environments. High-dimensional trait relationships and environmental clustering patterns were visualized using dimensionality reduction methods, including Uniform Manifold Approximation and Projection (UMAP) and t-distributed Stochastic Neighbor Embedding (t-SNE). Nested cross-validation was used to evaluate twelve machine learning regression models. The ridge regression showed the best predictive performance with a test R² of 0.8072 and RMSE of 183.77 kg/ha, while the nested cross-validation further confirmed robust generalization (R² = 0.7289 ± 0.0177). SHAP (SHapley Additive exPlanations) analysis revealed DF_BP_Interaction and thousand-seed weight (TSW) as the most important predictors of grain yield. AMMI and GGE biplot methods for genotype stability analysis revealed G71 and G63 as the most stable genotypes with better performances. Among the genotypes, G49 recorded the highest mean yield (1682.28 kg/ha) with moderate stability. Further, the GGE biplot showed the existence of two different mega-environments among the experimental locations, and Shyampur (L2) had the highest mean yield (1705.5 kg/ha). The proposed framework demonstrates the potential of combining interpretable machine learning with classical stability analysis for genotype selection and yield prediction in drought-stressed lentil production systems."
    },
    multitask: {
        title: "Multi-Task Convolutional Neural Network for Simultaneous Plant Disease Classification, Severity Estimation, Lesion Segmentation, and Leaf Localization",
        badge: "Conference Paper",
        metrics: "Accuracy: 99.56% | Macro F1: 0.9930 | Severity R²: 0.8908 | Severity MAE: 2.59% | Dice/IoU: 0.4057 / 0.3310 | Latency: 5.64ms/img",
        abstract: "Plant-disease diagnosis is more useful when a system reports not only disease identity but also severity, affected area, and leaf location. This paper presents an EfficientNetV2B0-based multi-task Convolutional Neural Network that performs 38-class disease classification, continuous severity regression, lesion segmentation, and whole-leaf localization in one forward pass. An Attention U-Net decoder predicts lesion masks, and a stop-gradient cross-task pathway supplies lesion-coverage evidence to the severity head. Because PlantVillage does not provide continuous severity scores or lesion masks, the framework uses CSV severity values, HSV-derived lesion pseudo-labels, and silhouette-derived bounding boxes. The completed ablation study evaluates six named configurations. The full multi-task model obtained 99.56% classification accuracy, macro F1 of 0.9930, severity MAE/RMSE of 2.59/5.38 percentage points, R² of 0.8908, Dice/IoU of 0.4057/0.3310, and normalized bounding-box MAE of 0.0354. Ablation results show that classification alone gives the highest disease accuracy, whereas auxiliary segmentation and cross-task fusion improve severity modelling. The framework provides an end-to-end baseline for actionable plant-disease assessment with limited manual annotation."
    },
    openset: {
        title: "Calibrated Open-Set Recognition for Robust Plant Disease Diagnosis under Unseen Diseases and Cross-Domain Distribution Shifts",
        badge: "Journal — Preprint",
        metrics: "Architecture: EfficientNetV2-B0 | Confidence Calibration: Temperature Scaling | OOD Metrics: MSP, Entropy, Energy, ODIN, OpenMax | Datasets: PlantVillage, PlantDoc, Plant Pathology 2020",
        abstract: "Deep-learning systems for plant disease recognition are commonly evaluated as closed-set classifiers, where every test image is assumed to belong to a disease class represented during training. In practical deployment, however, images may contain a disease never observed during training, come from a different image domain, or show non-plant/background content. A classifier can assign these unfamiliar inputs a confident known-class prediction, creating a reliability problem. This project proposes a calibrated open-set plant disease recognition framework that aims to retain useful classification performance on known diseases while identifying inputs that should be rejected or referred for review. The study uses PlantVillage as the principal controlled dataset and, subject to class compatibility and metadata validation, PlantDoc and Plant Pathology 2020 as external evaluation sources. An EfficientNetV2-B0 image classifier is trained, temperature scaling is used for confidence calibration, and multiple out-of-distribution (OOD) scoring approaches are compared (MSP, predictive entropy, energy, ODIN, OpenMax). Evaluation covers known-class classification, held-out disease recognition, cross-domain OOD detection, calibration, and selective prediction with risk-coverage analysis to reliably distinguish familiar from unfamiliar inputs."
    }
};

window.loadPaperAbstract = function(key) {
    const paper = PAPERS_DATA[key];
    const screen = document.getElementById('neurocore-output');
    if (!paper || !screen) return;

    // Highlight active chip
    document.querySelectorAll('.neurocore-chip').forEach(btn => {
        btn.classList.toggle('active', btn.getAttribute('data-paper') === key);
    });

    // Render metadata, key findings, and dynamic text streaming
    screen.innerHTML = `
        <div style="margin-bottom:12px;">
            <div style="display:flex;align-items:center;gap:8px;margin-bottom:6px;flex-wrap:wrap;">
                <span class="badge-preprint" style="font-size:0.75rem;padding:2px 8px;margin-bottom:0;">${paper.badge}</span>
                <span style="color:var(--text-muted);font-size:0.75rem;font-family:'Courier New',monospace;">ID: ${key.toUpperCase()}_v2.6</span>
            </div>
            <div style="color:var(--heading-color);font-weight:700;font-size:1.05rem;line-height:1.45;margin-bottom:8px;">${paper.title}</div>
            <div style="color:var(--secondary-color);font-size:0.82rem;background:rgba(255,255,255,0.06);padding:8px 12px;border-radius:8px;border-left:3px solid var(--secondary-color);margin-bottom:12px;line-height:1.5;">
                <i class="fas fa-chart-line" style="margin-right:6px;"></i> <strong>Key Quantitative Results:</strong> ${paper.metrics}
            </div>
        </div>
        <div style="font-size:0.88rem;line-height:1.7;color:var(--card-text);" id="abstract-stream"></div>
        <div style="margin-top:14px;display:flex;gap:12px;align-items:center;flex-wrap:wrap;">
            <a href="research.html" class="btn" style="font-size:0.82rem;padding:5px 14px;border-radius:6px;text-decoration:none;"><i class="fas fa-file-alt"></i> View in Research Portfolio</a>
        </div>
    `;

    const textTarget = document.getElementById('abstract-stream');
    let idx = 0;
    const fullText = paper.abstract;

    // Streaming typing effect
    const timer = setInterval(() => {
        if (idx < fullText.length) {
            const chunk = fullText.substring(0, Math.min(idx + 15, fullText.length));
            textTarget.innerHTML = `<strong style="color:var(--heading-color);"><i class="fas fa-align-left" style="color:var(--secondary-color);margin-right:4px;"></i> Abstract:</strong> ${chunk}<span class="neurocore-cursor"></span>`;
            idx += 15;
        } else {
            textTarget.innerHTML = `<strong style="color:var(--heading-color);"><i class="fas fa-align-left" style="color:var(--secondary-color);margin-right:4px;"></i> Abstract:</strong> ${fullText}`;
            clearInterval(timer);
        }
    }, 14);
};

// Initialize first paper on DOM ready
document.addEventListener('DOMContentLoaded', () => {
    if (document.getElementById('neurocore-output')) {
        loadPaperAbstract('manifold');
    }
});

// --- 4. TYPING TEXT ANIMATION ---
const typingText = document.querySelector('.typing-text');
if (typingText) {
    const text = typingText.textContent.trim();
    typingText.textContent = '';

    let charIndex = 0;
    function type() {
        if (charIndex < text.length) {
            typingText.textContent += text.charAt(charIndex);
            charIndex++;
            setTimeout(type, 65);
        } else {
            setTimeout(resetTyping, 3500);
        }
    }

    function resetTyping() {
        charIndex = 0;
        typingText.textContent = '';
        setTimeout(type, 500);
    }

    setTimeout(type, 800);
}

// --- 5. THEME TOGGLE (SYNC WITH SYSTEM & STORAGE) ---
window.toggleDarkMode = () => {
    const isDark = document.body.classList.toggle('dark-mode');
    localStorage.setItem('darkMode', isDark);
    updateToggleAria(isDark);
};

function updateToggleAria(isDark) {
    const btn = document.getElementById('theme-toggle');
    if (btn) {
        btn.setAttribute('aria-checked', isDark ? 'true' : 'false');
    }
}

(function initTheme() {
    const saved = localStorage.getItem('darkMode');
    const prefersDark = window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches;
    const shouldBeDark = saved !== null ? saved === 'true' : prefersDark;
    if (shouldBeDark) {
        document.body.classList.add('dark-mode');
    }
    updateToggleAria(shouldBeDark);
})();

// --- 6. NAVBAR SCROLL & HAMBURGER ---
const nav = document.querySelector('nav.site-nav');
window.addEventListener('scroll', () => {
    if (nav) nav.classList.toggle('scrolled', window.scrollY > 20);
}, { passive: true });

const navToggle = document.getElementById('nav-toggle');
const navMenu = document.querySelector('.site-nav .menu');
if (navToggle && navMenu) {
    navToggle.addEventListener('click', () => {
        const isOpen = navMenu.classList.toggle('open');
        const icon = navToggle.querySelector('i');
        if (icon) {
            icon.classList.toggle('fa-bars', !isOpen);
            icon.classList.toggle('fa-times', isOpen);
        }
    });

    navMenu.querySelectorAll('a').forEach(link => {
        link.addEventListener('click', () => {
            navMenu.classList.remove('open');
            const icon = navToggle.querySelector('i');
            if (icon) {
                icon.classList.add('fa-bars');
                icon.classList.remove('fa-times');
            }
        });
    });
}
