[[iframe width="1050px" height="800px" scrolling="no"]]
<!DOCTYPE html>
<html lang="he" dir="rtl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>דיאגרמת אורביטלים מולקולריים</title>
    
    <script>
        window.MathJax = {
            tex: { inlineMath: [['\\(', '\\)']] },
            startup: {
                ready: () => {
                    const mathEl = document.getElementById('math-title');
                    if (mathEl) {
                        mathEl.innerHTML = mathEl.innerHTML.replace(/&quot;/g, '').replace(/"/g, '');
                    }
                    MathJax.startup.defaultReady();
                }
            }
        };
    </script>
    <script async src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml.js"></script>

    <style>
        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        body {
            font-family: system-ui, -apple-system, sans-serif;
            background-color: #f8fafc;
            color: #1e293b;
            display: flex;
            flex-direction: column;
            align-items: center;
            padding: 1rem;
            overflow: hidden; 
        }

        /* FIXED DIMENSIONS CONTAINER */
        .app-container {
            display: grid;
            grid-template-columns: 260px 720px; 
            gap: 1rem;
            width: 1000px; 
            height: 760px; 
            margin: 0 auto;
        }

        .panel {
            background: #ffffff;
            padding: 1rem;
            border-radius: 12px;
            box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1);
            border: 1px solid #e2e8f0;
            height: 100%; 
            display: flex;
            flex-direction: column;
        }

        .header { text-align: center; margin-bottom: 1.5rem; }
        .header h1 { font-size: 1.4rem; color: #1e293b; }
        .header p { color: #64748b; font-size: 0.9rem; margin-top: 0.25rem; }

        .instructions { text-align: center; font-size: 0.85rem; color: #64748b; margin-bottom: 1rem; }
        
        .electrons-placed { text-align: center; margin-bottom: 1rem; }
        .electrons-placed label { display: block; font-size: 0.9rem; margin-bottom: 0.25rem; font-weight: bold; }
        .electrons-placed .count { font-size: 1.75rem; font-weight: bold; color: #2563eb; }

        .btn {
            width: 100%; padding: 0.6rem; font-size: 0.95rem; font-weight: 600;
            border: none; border-radius: 6px; background-color: #2563eb; color: white;
            cursor: pointer; transition: background-color 0.2s; margin-bottom: 1rem;
        }
        .btn:hover { background-color: #1d4ed8; }
        .btn:disabled { background-color: #94a3b8; cursor: not-allowed; }

        .stats { padding-top: 1rem; border-top: 1px solid #e2e8f0; }
        .stat-item { display: flex; justify-content: space-between; margin-bottom: 0.5rem; font-size: 0.9rem; }
        .stat-value { font-weight: bold; color: #2563eb; }

        /* Diagram Layout */
        .diagram-wrapper {
            width: 100%; 
            flex-grow: 1; 
            position: relative; 
            padding-left: 3rem;
            padding-top: 0.5rem;
        }

        .energy-axis {
            position: absolute; left: 50px; bottom: 1rem; top: 4.5rem; 
            width: 2px; background: #1e293b;
        }
        .energy-axis::before {
            content: ''; position: absolute; top: -10px; left: 50%; transform: translateX(-50%);
            border-left: 6px solid transparent; border-right: 6px solid transparent; border-bottom: 10px solid #1e293b;
        }
        .energy-axis::after {
            content: 'אנרגיה'; position: absolute; top: -30px; left: 50%; transform: translateX(-50%);
            font-weight: 600; font-size: 0.85rem; color: #1e293b;
        }

        .diagram-headers {
            display: grid; grid-template-columns: 1fr 1.2fr 1fr; text-align: center;
            margin-bottom: 2rem; 
            min-width: 400px;
            max-width: 500px;
            margin-left: auto;
            margin-right: auto;
        }

        .header-col {
            display: flex;
            justify-content: center;
            align-items: center;
            color: #64748b;
            font-weight: bold;
            font-size: 1.1rem;
            min-height: 38px;
            transition: all 0.3s ease;
        }

        .diagram-container-wrapper {
            position: relative;
            display: block;
            width: 100%;
        }

        .diagram-grid {
            display: grid; 
            grid-template-columns: 1fr 1.2fr 1fr;
            grid-template-rows: repeat(13, 30px); 
            row-gap: 14px; 
            column-gap: 2px;
            min-width: 400px; 
            max-width: 500px;
            margin-left: auto;
            margin-right: auto;
            position: relative;
        }
        .grid-cell { display: flex; flex-direction: column; align-items: center; justify-content: flex-end; position: relative; z-index: 10; }
        
        .level-label { 
            font-weight: 600; 
            font-size: 0.75rem; 
            color: #1e293b; 
            white-space: nowrap; 
            margin-top: 2px; 
        }

        .level-label.mo-label {
            margin-top: -3px; 
        }
        
        .orbital-group { display: flex; gap: 0.5rem; }

        .orbital {
            width: 30px; height: 30px; 
            border-bottom: 3px solid #dc2626 !important; 
            display: flex; justify-content: center; align-items: flex-end;
            font-size: 24px; 
            padding-bottom: 2px; position: relative;
            cursor: pointer; transition: background-color 0.2s; border-radius: 4px 4px 0 0;
            line-height: 1; 
        }
        .orbital:hover { background-color: #f1f5f9; }
        
        .arrow-up { color: #2563eb !important; font-weight: bold; } 
        .arrow-down { color: #1e293b !important; font-weight: bold; margin-left: -3px; }
        
        .empty-orbital { opacity: 1 !important; } 

        #stackFeedback { display: none; padding: 0.75rem; border-radius: 6px; font-size: 0.9rem; font-weight: bold; text-align: center; margin-top: 1rem; }
    </style>
</head>
<body>

    <div class="app-container">
        <div class="panel">
            <div class="instructions">
                לחץ על קווי האורביטלים כדי להוסיף או להסיר אלקטרונים.
            </div>

            <div class="electrons-placed">
                <label>אלקטרונים שמוקמו במולקולה:</label>
                <div class="count" id="placedElectronsMid">0</div>
            </div>

            <button class="btn" id="resetBtn" onclick="window.resetDiagram()">אפס דיאגרמה</button>

            <div class="stats">
                <div class="stat-item">
                    <span>אלקטרונים באטום 1:</span>
                    <span id="atom1Electrons" class="stat-value">0</span>
                </div>
                <div class="stat-item">
                    <span>אלקטרונים באטום 2:</span>
                    <span id="atom2Electrons" class="stat-value">0</span>
                </div>
                <div class="stat-item" style="border-top: 1px dashed #e2e8f0; padding-top: 0.5rem; margin-top: 0.5rem;">
                    <span>סדר קשר:</span>
                    <span id="bondOrder" class="stat-value">0</span>
                </div>
                <div class="stat-item">
                    <span>מגנטיות:</span>
                    <span id="magnetism" class="stat-value">-</span>
                </div>
            </div>

            <div id="stackFeedback"></div>
        </div>

        <div class="panel">
            <div class="header">
                <h1>דיאגרמת אורביטלים מולקולריים עבור <span id="math-title" dir="ltr">\({#mo_latex#}\)</span></h1>
                <p>אכלוס אלקטרונים אינטראקטיבי</p>
            </div>
            
            <div class="diagram-wrapper" dir="ltr">
                <div class="energy-axis"></div>
                <div class="diagram-headers">
                    <div id="header-atom1" class="header-col">אטום 1</div>
                    <div id="header-mol" class="header-col">מולקולה</div>
                    <div id="header-atom2" class="header-col">אטום 2</div>
                </div>
                
                <div class="diagram-container-wrapper">
                    <div class="diagram-grid" id="diagram"></div>
                </div>
            </div>
        </div>
    </div>

    <script type="module">
        import {stack_js} from '[[cors src="stackjsiframe.js"/]]';
        stack_js.resize_containing_frame(1050, 800);

        const orbitalConfigurations = {
            'sp-mixing': [
                { id: 'a1_2p', side: 'atom1', col: 1, row: 3, count: 3, label: '2p', type: 'ao' },
                { id: 'a2_2p', side: 'atom2', col: 3, row: 3, count: 3, label: '2p', type: 'ao' },
                { id: 'sigma2p_star', side: 'mid', col: 2, row: 1, count: 1, label: 'σ*<sub>2p</sub>', type: 'antibonding' },
                { id: 'pi2p_star', side: 'mid', col: 2, row: 2, count: 2, label: 'π*<sub>2p</sub>', type: 'antibonding' },
                { id: 'sigma2p', side: 'mid', col: 2, row: 4, count: 1, label: 'σ<sub>2p</sub>', type: 'bonding' },
                { id: 'pi2p', side: 'mid', col: 2, row: 5, count: 2, label: 'π<sub>2p</sub>', type: 'bonding' },
                
                { id: 'sigma2s_star', side: 'mid', col: 2, row: 7, count: 1, label: 'σ*<sub>2s</sub>', type: 'antibonding' },
                { id: 'a1_2s', side: 'atom1', col: 1, row: 8, count: 1, label: '2s', type: 'ao' },
                { id: 'a2_2s', side: 'atom2', col: 3, row: 8, count: 1, label: '2s', type: 'ao' },
                { id: 'sigma2s', side: 'mid', col: 2, row: 9, count: 1, label: 'σ<sub>2s</sub>', type: 'bonding' },
                
                { id: 'sigma1s_star', side: 'mid', col: 2, row: 11, count: 1, label: 'σ*<sub>1s</sub>', type: 'antibonding' },
                { id: 'a1_1s', side: 'atom1', col: 1, row: 12, count: 1, label: '1s', type: 'ao' },
                { id: 'a2_1s', side: 'atom2', col: 3, row: 12, count: 1, label: '1s', type: 'ao' },
                { id: 'sigma1s', side: 'mid', col: 2, row: 13, count: 1, label: 'σ<sub>1s</sub>', type: 'bonding' }
            ],
            'normal': [
                { id: 'a1_2p', side: 'atom1', col: 1, row: 3, count: 3, label: '2p', type: 'ao' },
                { id: 'a2_2p', side: 'atom2', col: 3, row: 3, count: 3, label: '2p', type: 'ao' },
                { id: 'sigma2p_star', side: 'mid', col: 2, row: 1, count: 1, label: 'σ*<sub>2p</sub>', type: 'antibonding' },
                { id: 'pi2p_star', side: 'mid', col: 2, row: 2, count: 2, label: 'π*<sub>2p</sub>', type: 'antibonding' },
                { id: 'pi2p', side: 'mid', col: 2, row: 4, count: 2, label: 'π<sub>2p</sub>', type: 'bonding' },
                { id: 'sigma2p', side: 'mid', col: 2, row: 5, count: 1, label: 'σ<sub>2p</sub>', type: 'bonding' },
                
                { id: 'sigma2s_star', side: 'mid', col: 2, row: 7, count: 1, label: 'σ*<sub>2s</sub>', type: 'antibonding' },
                { id: 'a1_2s', side: 'atom1', col: 1, row: 8, count: 1, label: '2s', type: 'ao' },
                { id: 'a2_2s', side: 'atom2', col: 3, row: 8, count: 1, label: '2s', type: 'ao' },
                { id: 'sigma2s', side: 'mid', col: 2, row: 9, count: 1, label: 'σ<sub>2s</sub>', type: 'bonding' },
                
                { id: 'sigma1s_star', side: 'mid', col: 2, row: 11, count: 1, label: 'σ*<sub>1s</sub>', type: 'antibonding' },
                { id: 'a1_1s', side: 'atom1', col: 1, row: 12, count: 1, label: '1s', type: 'ao' },
                { id: 'a2_1s', side: 'atom2', col: 3, row: 12, count: 1, label: '1s', type: 'ao' },
                { id: 'sigma1s', side: 'mid', col: 2, row: 13, count: 1, label: 'σ<sub>1s</sub>', type: 'bonding' }
            ]
        };

        const lineConnections = [
            { from: 'a1_1s', to: ['sigma1s', 'sigma1s_star'] },
            { from: 'a2_1s', to: ['sigma1s', 'sigma1s_star'] },
            { from: 'a1_2s', to: ['sigma2s', 'sigma2s_star'] },
            { from: 'a2_2s', to: ['sigma2s', 'sigma2s_star'] },
            { from: 'a1_2p', to: ['sigma2p', 'pi2p', 'pi2p_star', 'sigma2p_star'] },
            { from: 'a2_2p', to: ['sigma2p', 'pi2p', 'pi2p_star', 'sigma2p_star'] }
        ];

        const rawMixing = {#mixing_type#}; 
        const requiredMixing = (rawMixing === "sp-mixing" || rawMixing === "normal") ? rawMixing : 'normal';

        let currentState = [];
        window.isReadOnly = false;

        function buildDiagram() {
            const container = document.getElementById('diagram');
            const order = orbitalConfigurations[requiredMixing];
            
            container.innerHTML = '';
            currentState = [];

            const svg = document.createElementNS('http://www.w3.org/2000/svg', 'svg');
            svg.id = 'lines-svg';
            svg.style.position = 'absolute';
            svg.style.top = '0'; svg.style.left = '0';
            svg.style.width = '100%'; svg.style.height = '100%';
            svg.style.pointerEvents = 'none'; svg.style.zIndex = '0';
            container.appendChild(svg);

            order.forEach((level) => {
                const cellDiv = document.createElement('div');
                cellDiv.className = 'grid-cell';
                cellDiv.style.gridColumn = level.col;
                cellDiv.style.gridRow = level.row;
                cellDiv.dataset.levelId = level.id;

                const orbitalGroup = document.createElement('div');
                orbitalGroup.className = 'orbital-group';

                for (let i = 0; i < level.count; i++) {
                    const stateObj = { level: level, electrons: 0 };
                    currentState.push(stateObj);
                    
                    const orbitalDiv = document.createElement('div');
                    orbitalDiv.className = 'orbital empty-orbital';
                    orbitalDiv.dataset.stateIndex = currentState.length - 1;
                    orbitalDiv.addEventListener('click', handleOrbitalClick);
                    orbitalGroup.appendChild(orbitalDiv);
                }

                cellDiv.appendChild(orbitalGroup);

                const labelDiv = document.createElement('div');
                labelDiv.className = 'level-label';
                
                if (level.side === 'mid') {
                    labelDiv.classList.add('mo-label');
                }
                
                labelDiv.innerHTML = level.label;
                cellDiv.appendChild(labelDiv);

                container.appendChild(cellDiv);
            });

            updateStats();
            requestAnimationFrame(drawConnectingLines);
        }

        function drawConnectingLines() {
            const svg = document.getElementById('lines-svg');
            const container = document.getElementById('diagram');
            if (!svg || !container) return;
            
            svg.innerHTML = ''; 
            const containerRect = container.getBoundingClientRect();

            lineConnections.forEach(conn => {
                const fromCell = container.querySelector(`[data-level-id="${conn.from}"] .orbital-group`);
                if (!fromCell) return;
                
                const fromRect = fromCell.getBoundingClientRect();
                let fromX, fromY;
                
                if (conn.from.startsWith('a1')) {
                    fromX = fromRect.right - containerRect.left + 5;
                } else {
                    fromX = fromRect.left - containerRect.left - 5;
                }
                fromY = fromRect.bottom - containerRect.top - 2;

                conn.to.forEach(toId => {
                    const toCell = container.querySelector(`[data-level-id="${toId}"] .orbital-group`);
                    if (!toCell) return;
                    
                    const toRect = toCell.getBoundingClientRect();
                    let toX;
                    
                    if (conn.from.startsWith('a1')) {
                        toX = toRect.left - containerRect.left - 5;
                    } else {
                        toX = toRect.right - containerRect.left + 5;
                    }
                    const toY = toRect.bottom - containerRect.top - 2;

                    const line = document.createElementNS('http://www.w3.org/2000/svg', 'line');
                    line.setAttribute('x1', fromX); line.setAttribute('y1', fromY);
                    line.setAttribute('x2', toX); line.setAttribute('y2', toY);
                    
                    line.setAttribute('stroke', '#475569'); 
                    line.setAttribute('stroke-width', '2');
                    line.setAttribute('stroke-dasharray', '4,4');
                    svg.appendChild(line);
                });
            });
        }

        function handleOrbitalClick(e) {
            if (window.isReadOnly) return;
            const box = e.currentTarget;
            const index = box.dataset.stateIndex;
            let stateObj = currentState[index];
            
            stateObj.electrons = (stateObj.electrons + 1) % 3;
            
            if (stateObj.electrons === 0) {
                box.innerHTML = '';
                box.classList.add('empty-orbital');
            } else if (stateObj.electrons === 1) {
                box.innerHTML = '<span class="arrow-up">↑</span>';
                box.classList.remove('empty-orbital');
            } else {
                box.innerHTML = '<span class="arrow-up">↑</span><span class="arrow-down">↓</span>';
                box.classList.remove('empty-orbital');
            }
            
            updateStats();
            if (window.updateStackState) window.updateStackState();
        }

        function updateStats() {
            let atom1Total = 0; let atom2Total = 0; let midTotal = 0;
            let bondingElectrons = 0; let antibondingElectrons = 0;
            let hasUnpaired = false;

            currentState.forEach(obj => {
                if (obj.level.side === 'atom1') atom1Total += obj.electrons;
                if (obj.level.side === 'atom2') atom2Total += obj.electrons;
                if (obj.level.side === 'mid') {
                    midTotal += obj.electrons;
                    if (obj.level.type === 'bonding') bondingElectrons += obj.electrons;
                    if (obj.level.type === 'antibonding') antibondingElectrons += obj.electrons;
                    if (obj.electrons === 1) hasUnpaired = true;
                }
            });

            document.getElementById('atom1Electrons').innerText = atom1Total;
            document.getElementById('atom2Electrons').innerText = atom2Total;
            document.getElementById('placedElectronsMid').innerText = midTotal;
            
            const bondOrder = (bondingElectrons - antibondingElectrons) / 2;
            document.getElementById('bondOrder').innerText = midTotal === 0 ? "0" : bondOrder;
            
            const magnetismEl = document.getElementById('magnetism');
            if (midTotal === 0) {
                document.getElementById('bondOrder').innerText = "0";
                magnetismEl.innerText = "-"; magnetismEl.style.color = "#64748b";
            } else if (hasUnpaired) {
                magnetismEl.innerText = "פראמגנטי"; magnetismEl.style.color = "#dc2626";
            } else {
                magnetismEl.innerText = "דיאמגנטי"; magnetismEl.style.color = "#2563eb";
            }
        }

        window.resetDiagram = function() {
            if (window.isReadOnly) return;
            buildDiagram();
            if (window.updateStackState) window.updateStackState();
        };

        function setBadge(elementId, text, isCorrect) {
            const el = document.getElementById(elementId);
            el.style.display = 'inline-flex';
            el.style.alignItems = 'center';
            el.style.justifyContent = 'center';
            el.style.gap = '6px';
            el.style.padding = '0';
            el.style.borderRadius = '0'; 
            el.style.fontWeight = 'bold';
            el.style.margin = '0 auto';
            el.style.fontSize = '1.1rem'; 
            el.style.backgroundColor = 'transparent'; 
            el.style.border = 'none'; 
            
            if (isCorrect) {
                el.style.color = '#1e293b';
                el.innerHTML = `
                    <span>${text}</span>
                    <span style="color: #16a34a; font-weight: bold; font-size: 1.2em;">✓</span>
                `;
            } else {
                el.style.color = '#1e293b';
                el.innerHTML = `
                    <span>${text}</span>
                    <span style="color: #dc2626; font-weight: bold; font-size: 1.2em;">✕</span>
                `;
            }
        }

        // ==========================================
        // STACK-JS GRADING BRIDGE 
        // ==========================================
        var promiseforaninput = stack_js.request_access_to_input("ans1", true);

        promiseforaninput.then((id) => {
            
           function initApp() {
                buildDiagram();
                window.addEventListener('resize', drawConnectingLines);

                let stackInput = document.getElementById(id);
                let isInternalUpdate = false;
                let lastKnownValue = stackInput.value || "";

                const expectedAtom1 = {#conf_atom1#}; 
                const expectedAtom2 = {#conf_atom2#}; 
                const expectedMol = {#conf_mol#};      

                function arraysMatch(arr1, arr2) {
                    function extractNumbers(input) {
                        if (input === null || input === undefined) return [];
                        let str = typeof input === 'string' ? input : JSON.stringify(input);
                        
                        let nums = [];
                        let currentNum = "";
                        
                        for (let i = 0; i < str.length; i++) {
                            let char = str[i];
                            if (char >= '0' && char <= '9') {
                                currentNum += char;
                            } else if (currentNum.length > 0) {
                                nums.push(parseInt(currentNum, 10));
                                currentNum = "";
                            }
                        }
                        if (currentNum.length > 0) {
                            nums.push(parseInt(currentNum, 10));
                        }
                        return nums;
                    }

                    let nums1 = extractNumbers(arr1);
                    let nums2 = extractNumbers(arr2);
                    
                    while(nums1.length > 0 && nums1[nums1.length - 1] === 0) nums1.pop();
                    while(nums2.length > 0 && nums2[nums2.length - 1] === 0) nums2.pop();

                    if (nums1.length !== nums2.length) return false;
                    for (let i = 0; i < nums1.length; i++) {
                        if (nums1[i] !== nums2[i]) return false;
                    }
                    return true;
                }

                function getCurrentConfig(side) {
                    let levels = {};
                    currentState.forEach(obj => {
                        if (obj.level.side === side) {
                            if (!levels[obj.level.row]) levels[obj.level.row] = 0;
                            levels[obj.level.row] += obj.electrons;
                        }
                    });
                    let sortedRows = Object.keys(levels).map(Number).sort((a, b) => b - a);
                    return sortedRows.map(row => levels[row]);
                }

                // NEW: Checks if Hund's Rule is followed within degenerate orbitals 
                function isHundsRuleObeyed(side) {
                    let rows = {};
                    currentState.forEach(obj => {
                        if (obj.level.side === side) {
                            if (!rows[obj.level.row]) rows[obj.level.row] = [];
                            rows[obj.level.row].push(obj.electrons);
                        }
                    });
                    
                    for (let row in rows) {
                        let counts = rows[row];
                        let total = counts.reduce((a, b) => a + b, 0);
                        
                        let expectedCounts = new Array(counts.length).fill(0);
                        let e = total;
                        for(let i=0; i<counts.length && e>0; i++) { expectedCounts[i] = 1; e--; }
                        for(let i=0; i<counts.length && e>0; i++) { expectedCounts[i] = 2; e--; }
                        
                        counts.sort((a,b) => b - a);
                        expectedCounts.sort((a,b) => b - a);
                        
                        for(let i=0; i<counts.length; i++) {
                            if (counts[i] !== expectedCounts[i]) return false;
                        }
                    }
                    return true;
                }

                window.updateStackState = function() {
                    let currentAtom1 = getCurrentConfig('atom1');
                    let currentAtom2 = getCurrentConfig('atom2');
                    let currentMol = getCurrentConfig('mid');
                    
                    let a1Hund = isHundsRuleObeyed('atom1');
                    let a2Hund = isHundsRuleObeyed('atom2');
                    let molHund = isHundsRuleObeyed('mid');
                    
                    let grade = 0.0;
                    
                    let a1Correct = false;
                    let a2Correct = false;
                    let e1Used = false;
                    let e2Used = false;

                    if (arraysMatch(currentAtom1, expectedAtom1) && a1Hund) {
                        a1Correct = true; e1Used = true;
                    } else if (arraysMatch(currentAtom1, expectedAtom2) && a1Hund) {
                        a1Correct = true; e2Used = true;
                    }

                    if (arraysMatch(currentAtom2, expectedAtom2) && a2Hund && !e2Used) {
                        a2Correct = true; e2Used = true;
                    } else if (arraysMatch(currentAtom2, expectedAtom1) && a2Hund && !e1Used) {
                        a2Correct = true; e1Used = true;
                    }

                    if (a1Correct && a2Correct) {
                        grade += 0.4;
                    } else if (a1Correct || a2Correct) {
                        grade += 0.2;
                    }

                    if (arraysMatch(currentMol, expectedMol) && molHund) {
                        grade += 0.6;
                    }
                    
                    grade = Math.round(grade * 100) / 100; 

                    // Store EXACT box-by-box state to prevent "auto-fixing" on reload
                    let exactState = currentState.map(obj => obj.electrons);

                    let payload = JSON.stringify([grade, currentAtom1, currentAtom2, currentMol, exactState]);
                    
                    isInternalUpdate = true;
                    stackInput.value = payload; 
                    lastKnownValue = payload; 

                    stackInput.dispatchEvent(new Event('change'));
                    isInternalUpdate = false;
                };

                // Fallback for older saves where exactState didn't exist
                function applyElectronsToRow(side, row, totalElectrons) {
                    let boxes = currentState.filter(obj => obj.level.side === side && obj.level.row === row);
                    boxes.forEach(b => b.electrons = 0); 
                    let e = totalElectrons;
                    for(let i=0; i<boxes.length && e>0; i++) { boxes[i].electrons = 1; e--; }
                    for(let i=0; i<boxes.length && e>0; i++) { boxes[i].electrons = 2; e--; }
                }

                function syncDOMWithState() {
                    currentState.forEach((obj, index) => {
                        const box = document.querySelector(`.orbital[data-state-index="${index}"]`);
                        if(!box) return;
                        if (obj.electrons === 0) {
                            box.innerHTML = '';
                            box.classList.add('empty-orbital');
                        } else if (obj.electrons === 1) {
                            box.innerHTML = '<span class="arrow-up">↑</span>';
                            box.classList.remove('empty-orbital');
                        } else {
                            box.innerHTML = '<span class="arrow-up">↑</span><span class="arrow-down">↓</span>';
                            box.classList.remove('empty-orbital');
                        }
                    });
                    updateStats();
                }

                function loadFromArrays(atom1Arr, atom2Arr, molArr) {
                    let getSortedRows = (side) => {
                        let rows = new Set();
                        currentState.forEach(obj => { if(obj.level.side === side) rows.add(obj.level.row); });
                        return Array.from(rows).sort((a,b) => b - a);
                    };
                    let atom1Rows = getSortedRows('atom1');
                    let atom2Rows = getSortedRows('atom2');
                    let molRows = getSortedRows('mid');

                    atom1Arr.forEach((val, idx) => applyElectronsToRow('atom1', atom1Rows[idx], val));
                    atom2Arr.forEach((val, idx) => applyElectronsToRow('atom2', atom2Rows[idx], val));
                    molArr.forEach((val, idx) => applyElectronsToRow('mid', molRows[idx], val));

                    syncDOMWithState();
                }

                function handleExternalInputChange() {
                    try {
                        if(!stackInput.value) return;
                        let data = JSON.parse(stackInput.value);
                        if (Array.isArray(data)) {
                            if (data.length >= 5 && Array.isArray(data[4])) {
                                // Load exact UI state
                                let exactState = data[4];
                                currentState.forEach((obj, idx) => {
                                    obj.electrons = exactState[idx] || 0;
                                });
                                syncDOMWithState();
                            } else if (data.length >= 4) {
                                // Fallback for old save arrays
                                loadFromArrays(data[1], data[2], data[3]);
                            }
                        }
                    } catch(e) { console.error("Error parsing STACK input", e); }
                }

                setInterval(() => {
                    if (!isInternalUpdate && stackInput.value !== lastKnownValue) {
                        lastKnownValue = stackInput.value;
                        handleExternalInputChange();
                    }
                }, 300);

                if (stackInput.value) {
                    handleExternalInputChange();
                }

                if (stackInput.readOnly || stackInput.disabled) {
                    window.isReadOnly = true;
                    document.getElementById('diagram').style.pointerEvents = 'none';
                    document.getElementById('resetBtn').disabled = true;

                    let currentAtom1 = getCurrentConfig('atom1');
                    let currentAtom2 = getCurrentConfig('atom2');
                    let currentMol = getCurrentConfig('mid');
                    
                    let a1Hund = isHundsRuleObeyed('atom1');
                    let a2Hund = isHundsRuleObeyed('atom2');
                    let molHund = isHundsRuleObeyed('mid');
                    
                    let atom1Correct = false;
                    let atom2Correct = false;
                    let exp1Used = false;
                    let exp2Used = false;

                    if (arraysMatch(currentAtom1, expectedAtom1) && a1Hund) {
                        atom1Correct = true; exp1Used = true;
                    } else if (arraysMatch(currentAtom1, expectedAtom2) && a1Hund) {
                        atom1Correct = true; exp2Used = true;
                    }

                    if (arraysMatch(currentAtom2, expectedAtom2) && a2Hund && !exp2Used) {
                        atom2Correct = true; exp2Used = true;
                    } else if (arraysMatch(currentAtom2, expectedAtom1) && a2Hund && !exp1Used) {
                        atom2Correct = true; exp1Used = true;
                    }

                    let atomsCorrect = atom1Correct && atom2Correct;
                    let molCorrect = arraysMatch(currentMol, expectedMol) && molHund;

                    setBadge('header-atom1', 'אטום 1', atom1Correct);
                    setBadge('header-atom2', 'אטום 2', atom2Correct);
                    setBadge('header-mol', 'מולקולה', molCorrect);

                    const feedbackDiv = document.getElementById('stackFeedback');
                    feedbackDiv.style.display = 'block';
                    
                    if (atomsCorrect && molCorrect) {
                        feedbackDiv.innerHTML = "<span style='color: #16a34a; font-weight: bold;'>✓</span> כל הכבוד! האורביטלים אוכלסו בצורה נכונה.";
                        feedbackDiv.style.backgroundColor = '#dcfce7';
                        feedbackDiv.style.color = '#166534';
                        feedbackDiv.style.border = '1px solid #22c55e';
                    } else {
                        feedbackDiv.innerHTML = "<span style='color: #dc2626; font-weight: bold;'>✕</span> ישנה שגיאה באכלוס האורביטלים.";
                        feedbackDiv.style.backgroundColor = '#fee2e2';
                        feedbackDiv.style.color = '#991b1b';
                        feedbackDiv.style.border = '1px solid #ef4444';
                    }
                }
            } 

            if (document.readyState === 'loading') {
                document.addEventListener('DOMContentLoaded', initApp);
            } else {
                initApp();
            }
        });
    </script>
</body>
</html>
[[/iframe]]
