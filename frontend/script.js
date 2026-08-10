async function loadBooks() {
    const statusEl = document.getElementById("status");
    const listEl = document.getElementById("book-list");

    statusEl.textContent = "Loading...";

    try {
        const res = await fetch("/books");

        if (!res.ok) {
            throw new Error(`Server responded with ${res.status}`);
        }

        const books = await res.json();

        listEl.innerHTML = "";

        if (books.length === 0) {
            statusEl.textContent = "No books found.";
            return;
        }

        statusEl.textContent = `Found ${books.length} books.`;

        books.forEach(book => {
            const li = document.createElement("li");

            const link = document.createElement("a");
            link.href = "#";
            link.textContent = `#${book.id} - ${book.title}`;
            link.onclick = (e) => {
                e.preventDefault();
                openPdf(book.filename);
            };

            li.appendChild(link);
            listEl.appendChild(li);
        });

    } catch (err) {
        statusEl.textContent = `Error: ${err.message}`;
        console.error(err);
    }
}

function openPdf(filename) {
    const frame = document.getElementById("pdf-frame");
    const modal = document.getElementById("pdf-modal");

    frame.src = `/pdf/${encodeURIComponent(filename)}`;
    modal.classList.remove("hidden");
}

function closePdf() {
    const frame = document.getElementById("pdf-frame");
    const modal = document.getElementById("pdf-modal");

    modal.classList.add("hidden");
    frame.src = "";
}

document.getElementById("pdf-close").addEventListener("click", closePdf);

document.addEventListener("keydown", (e) => {
    if (e.key === "Escape") {
        closePdf();
    }
});

loadBooks();