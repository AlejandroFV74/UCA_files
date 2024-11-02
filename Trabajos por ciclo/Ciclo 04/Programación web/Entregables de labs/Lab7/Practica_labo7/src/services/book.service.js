export const addAuthorToBook = async (book, authorId) => {
    try {
        const existAuthor = book.authors.find(author => author.toString() === authorId);
        if (existAuthor) throw new ServiceError('El autor ya fue asignado al libro',
            BookErrorCodes.AUTHOR_ALREADY_ASSIGNED);
        book.authors.push(authorId);
        const bookUpdated = await book.save();
        return bookUpdated;
    } catch (error) {
        throw new ServiceError('Error al asignar el autor a',
            BookErrorCodes.AUTHOR_ASSIGN_FAILED);
    }
}